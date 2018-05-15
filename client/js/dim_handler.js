DEFAULT_XDIM_PMAT = 3
DEFAULT_YDIM_PMAT = 4

$(document).ready(function() {
    cellValues = {}

    function checkVal(cellID){
        if (cellID in cellValues){
            return cellValues[cellID]
        }
        return '0'
    }

    function setVal(cellID){
        cellValues[cellID] = $('#' + cellID).val()
        console.log(cellValues)
    }

    function updateParityDims(xdim, ydim){
        table = $('#parityTable')
        cells = ''
        for (y = 0; y < ydim; y++){
            cells += '<div class="form-group row">'
            for (x = 0; x < xdim; x++){
                id = 'pmat'+ x +'x' + y
                cell = '<input type="text" class="form-control col cell" value="' + checkVal(id) + '" id="' + id + '">'
                cells += cell
            }
            cells += '</div>'
        }
        table.empty().append(cells)

        divIDs = ['recSeq', 'logValDec', 'logValNDec']
        for (divID of divIDs){
            div = $('#' + divID)
            cells = ''
            for (x = 0; x < xdim; x++){
                id = divID + x +'x' + y
                cell = '<input type="text" class="form-control col cell" value="' + checkVal(id) + '" id="' + id + '">'
                cells += cell
            }
            div.find('input').remove()
            div.append(cells)
        }

        $('.cell').keyup(function(event){
            var target = $( event.target )
            setVal(target.attr('id'))
        });
    }

    $('.dim').keyup(function(){
        ydim = $('#ydim').val()
        xdim = $('#xdim').val()
        updateParityDims(xdim, ydim)
    });

    $('#table').click(function(){
        data = $('#request').val()
        send_data(data)
    });

    $('#xdim').val(DEFAULT_XDIM_PMAT)
    $('#ydim').val(DEFAULT_YDIM_PMAT)
    updateParityDims($('#xdim').val(), $('#ydim').val())
});