$(document).ready(function() {
    var socket = io()

    function send_data(data){
        socket.emit('data', data)
    }

    $('#sendButton').click(function(){
        data = $('#request').val()
        send_data(data)
    });


    socket.on('data', function(msg){     
        console.log(msg)
        $('#response').val(msg)
    });
});