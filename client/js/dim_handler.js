DEFAULT_XDIM_PMAT = 3
DEFAULT_YDIM_PMAT = 4
DEFAULT_ITERATIONS = 1

$(document).ready(function () {
    cellValues = {}

    /**
     * get values from cellValues dictionary
     * return 0 if value not found
     * 
     * @param {*} cellID 
     */
    function checkVal(cellID) {
        if (cellID in cellValues) {
            return cellValues[cellID]
        }
        return '0'
    }

    function setVal(cellID) {
        cellValues[cellID] = $('#' + cellID).val()
    }

    function updateParityDims(xdim, ydim) {
        table = $('#parityTable')
        cells = ''
        for (y = 0; y < ydim; y++) {
            cells += '<div class="form-group row">'
            for (x = 0; x < xdim; x++) {
                id = 'pmat' + y + 'x' + x
                cell = '<input type="text" class="form-control col cell parity" \
                        value="' + checkVal(id) + '" \
                        id="' + id + '">'
                cells += cell
            }
            cells += '</div>'
        }
        table.empty().append(cells)
    }

    function updateOtherDims(xdim, ydim){
        divIDs = ['recSeq', 'logValDec', 'logValNDec']
        for (divID of divIDs) {
            div = $('#' + divID)
            cells = ''
            for (x = 0; x < xdim; x++) {
                id = divID + x
                cl = divID
                setReadonly = function(){ if (divID != "recSeq") return "readonly" }
                cell = '<input type="text" \
                        class="form-control col cell ' + cl + '" \
                        value="' + checkVal(id) + '" \
                        id="' + id + '"' +
                        setReadonly() + '>'
                cells += cell
            }
            div.find('input').remove()
            div.append(cells)
        }
    }

    // Updates the # of cells for ui elements
    function updateDims(xdim, ydim) {
        updateParityDims(xdim, ydim)
        updateOtherDims(xdim, ydim)

        // set keyup event for all cells
        // store value to checkVal dict
        $('.cell').keyup(function (event) {
            var target = $(event.target)
            setVal(target.attr('id'))
        });
    }

    // Trigger updateDims upon typing into dim inputs
    $('.dim').keyup(function () {
        ydim = $('#ydim').val()
        xdim = $('#xdim').val()
        updateDims(xdim, ydim)
    });

    $('#iterations').val(DEFAULT_ITERATIONS)
    $('#xdim').val(DEFAULT_XDIM_PMAT)
    $('#ydim').val(DEFAULT_YDIM_PMAT)
    updateDims($('#xdim').val(), $('#ydim').val())
});