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
            var data = data.replace('200','');
            var dataList = data.split('\n')

            var id = 'logValDec'
            if ( $('#iterations').val() == 1 ){
                id = 'logValNDec'
            }

            for (liloc in dataList){
                $('#' + id + liloc).val(dataList[liloc])
            }

            $('#response').val(data)
            clearError()
        } else {
            setError(data)
        }
    }

    $('#decodeButton').click(function(){
        data = formatRequest()
        sendData(data)
    });


    socket.on('data', function(msg){     
        console.log(msg)
        handleData(msg)
    });
});