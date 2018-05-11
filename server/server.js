var express = require('express');
var app = express();
var server = require('http').Server(app);
var io = require('socket.io')(server);
var uniqueFilename = require('unique-filename');
var path = require('path');
var os = require('os');
var fs = require('fs');

CLIENT_FILES_DIR = path.resolve(__dirname + '/../client/')
PORT = 80

app.use('/css', express.static(CLIENT_FILES_DIR + '/css'));
app.use('/js', express.static(CLIENT_FILES_DIR + '/js'));

app.get('/', function (req, res) {
    res.sendfile(CLIENT_FILES_DIR + '/index.html');
});


function createTmpFile(text) {
    var randomTmpfile = uniqueFilename(os.tmpdir(), 'LDPCpp');

    try {
        fs.writeFileSync(randomTmpfile, text);
        console.log('Created: ' + randomTmpfile)
        return randomTmpfile
    } catch (err) {
        console.log(err)
        return null
    }
}

function deleteTmpFile(fname) {
    try {
        fs.unlinkSync(fname);
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
        // save msg to tmp file
        fname = createTmpFile('TEXT!')

        // call .exe

        // get output of .exe (as file or std out)

        // emit output to client

        socket.emit('data', 'pong: ' + msg);

        // remove tmp file
        deleteTmpFile(fname)
    });

});

server.listen(PORT, function () {
    console.log('listening on *:' + PORT);
});