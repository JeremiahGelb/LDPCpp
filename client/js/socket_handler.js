$(document).ready(function() {
    var socket = io()

    socket.emit('data', 'TEST!')

    socket.on('data', function(msg){
        console.log(msg)
    });
});