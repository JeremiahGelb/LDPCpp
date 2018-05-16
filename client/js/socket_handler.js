$(document).ready(function() {
    var socket = io()

    function sendData(data){
        socket.emit('data', data)
    }

    // sets alert to visible, changes alert text
    function setError(msg){
        $('.alert').css('visibility', 'visible').text(msg)
    }

    // clears out alert
    function clearError(){
        $('.alert').css('visibility', 'hidden')
    }

    function handleData(data){
        // check for success
        if (data.startsWith('200\n')){
            var data = data.replace('200\n','');
            var dataList = data.split('\n')

            var id = 'logValDec'
            if ( $('#iterations').val() == 0 ){
                id = 'logValNDec'
            }

            for (liloc in dataList){
                $('#' + id + liloc).val(dataList[liloc])
            }

            $('#response').val(data)
            clearError()

        // if not success, must be an error
        } else {
            setError(data)
        }
    }

    $('#decodeButton').click(function(){
        data = formatRequest()
        sendData(data)
    });


    socket.on('data', function(msg){
        handleData(msg)
    });
});