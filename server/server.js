var express = require('express');
var app = express();
var server = require('http').Server(app);
var io = require('socket.io')(server);

CLIENT_FILES_DIR = '../client'
PORT = 80

// app.use( CLIENT_FILES_DIR + '/css', express.static(__dirname + '/css'));
app.use( CLIENT_FILES_DIR + '/js', express.static(__dirname + '/js'));

app.get( CLIENT_FILES_DIR, function(req, res){
    res.sendfile('index.html');
});


io.on('connection', function(socket){
    console.log('user connected');

    socket.on('data', function(msg){
        // save msg to file
        
        // call .exe

        // get output of .exe (as file or std out)

        // emit output to client

        socket.emit('data', 'pong! ' + msg);
    });

});

server.listen(PORT, function(){
    console.log('listening on *:' + PORT);
});