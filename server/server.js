var express = require('express');
var app = express();
var server = require('http').Server(app);
var io = require('socket.io')(server);

CLIENT_FILES_DIR = __dirname + '/../client/'
PORT = 80

app.use('/css', express.static(CLIENT_FILES_DIR + '/css'));
app.use('/js', express.static(CLIENT_FILES_DIR + '/js'));

app.get('/', function (req, res) {
    res.sendfile(CLIENT_FILES_DIR + 'index.html');
});


io.on('connection', function (socket) {
    console.log('user connected');

    socket.on('data', function (msg) {
        // save msg to file

        // call .exe

        // get output of .exe (as file or std out)

        // emit output to client

        socket.emit('data', 'pong: ' + msg);
    });

});

server.listen(PORT, function () {
    console.log('listening on *:' + PORT);
});