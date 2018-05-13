$(document).ready(function() {
    var socket = io()

    function send_data(data){
        socket.emit('data', data)
    }

    function display_data(data){
        if (data.startsWith('200')){
            data = data.replace('200','');
            $('#response').val(data)
        } else {
            $('#response').val('Error?\n' + data)
        }
    }

    $('#sendButton').click(function(){
        data = $('#request').val()
        send_data(data)
    });


    socket.on('data', function(msg){     
        console.log(msg)
        display_data(msg)
    });
});