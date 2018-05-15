$(document).ready(function() {
    var socket = io()

    function sendData(data){
        socket.emit('data', data)
    }

    function setError(msg){
        $('.alert').css('visibility', 'visible').text(msg)
    }

    function clearError(){
        $('.alert').css('visibility', 'hidden')
    }

    function handleData(data){
        if (data.startsWith('200')){
            data = data.replace('200','');
            $('#response').val(data)
            clearError()
        } else {
            setError(data)
        }
    }

    $('#decodeButton').click(function(){
        data = $('#request').val()
        sendData(data)
    });


    socket.on('data', function(msg){     
        console.log(msg)
        handleData(msg)
    });
});