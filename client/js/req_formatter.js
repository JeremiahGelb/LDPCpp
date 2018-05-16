function formatRequest() {
    var request = 0

    var output = ''

    output += $('#ydim').val() + '\n'
    output += $('#xdim').val() + '\n'

    classes = ['.parity', '.recSeq']
    for (cl of classes) {
        for (cell of $(cl)) {
            jqcell = $(cell)
            if (jqcell.hasClass('logValDec') || jqcell.hasClass('logValNDec')) {
                continue
            }
            output += jqcell.val() + '\n'
        }
    }

    output += '1' + '\n'
    output += $('#iterations').val()

    console.log(output)

    return output
}
