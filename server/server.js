var express = require('express');
var app = express();
var server = require('http').Server(app);
var io = require('socket.io')(server);
var uniqueFilename = require('unique-filename');
var path = require('path');
var os = require('os');
var fs = require('fs');
var cp = require('child_process');

CLIENT_FILES_DIR = path.resolve(__dirname + '/../client/')
PORT = 80

app.use('/css', express.static(CLIENT_FILES_DIR + '/css'));
app.use('/js', express.static(CLIENT_FILES_DIR + '/js'));

app.get('/', function (req, res) {
    res.sendfile(CLIENT_FILES_DIR + '/index.html');
});


function createTmpFiles(text) {
    var randomTmpfile = uniqueFilename(os.tmpdir(), 'LDPCpp');

    try {
        fs.writeFileSync(randomTmpfile + '-request', text);
        fs.writeFileSync(randomTmpfile + '-response', '');
        console.log('Created: ' + randomTmpfile)
        return randomTmpfile
    } catch (err) {
        console.log(err)
        return null
    }
}

function getTmpFileData(fname) {
    var content = ''
    try {
        content = fs.readFileSync(fname + '-response')
        console.log('Read from: ' + content)
        return content
    } catch (err) {
        console.log(err)
        return null
    }
}

function deleteTmpFiles(fname) {
    try {
        fs.unlinkSync(fname + '-request');
        fs.unlinkSync(fname + '-response');
        console.log('Deleted: ' + fname)
        return true
    } catch (err) {
        console.log(err)
        return false
    }
}

io.on('connection', function (socket) {
    console.log('user connected');

    socket.on('data', function (msg) {
        try {
            // save msg to tmp file
            fname = createTmpFiles(msg)

            // call .exe
            cp.execSync('./RunMe.exe 2 ' + fname + '-request ' + fname + '-response')

            // get output of tmp response file
            content = getTmpFileData(fname)

            // emit content to client
            socket.emit('data', String(content));

        } catch (err) {
            console.log(err)
            socket.emit('data', String(err));
        }

        // remove tmp files
        deleteTmpFiles(fname)
    });

});

server.listen(PORT, function () {
    console.log('listening on *:' + PORT);
});