jQuery(document).ready(function() {
    $('#translate').click(function() {
		$.ajax({
		    type: 'POST',
		    url: 'service.php',
		    data: { act: 'decode', morse: $('#morse').val() },
		    dataType: 'json',
		    success: function (data) {
			if (data.status != 0) {
			    $('#result').val("Error: " + data.error);
			    $('#result').show('slow');
			} else {
			    $('#panel-last').append(
				'<div class="panel-group" id="accordion">' +
				    '<div class="panel panel-default">' +
				    '<div class="panel-heading">' +
				    '<h4 class="panel-title">' +
				    '<a data-toggle="collapse" data-parent="#accordion" href="#id' + data.id + '">[' + data.id + '] ' + data.date + '</a>' +
				    '</h4>' +
				    '</div>' +
				    '<div id="id' + data.id + '" class="panel-collapse collapse in">' +
				    '<div class="panel-body">' + data.text + '</div>' +
				    '</div>' +
				    '</div>' +
				    '</div>');
			    $('#result').val(data.text);
			    $('#result').show('slow');
			}
		    }
		});
    });

    $('#clear').click(function() {
	$('#morse').val('');
	$('#result').hide('slow');
	$('#result').val('');
    });
});
