function submit_form(obj)
{
    f = obj.getElementsByTagName('input');
    data = {};
    for (var i = 0 ; i < f.length ;i++)
	data[f[i].name] = f[i].value;

    $.post(obj.attributes.action.value, data,
	   function(res)
	   {
	       if (res != "ok")
	       {
		   $("#errmsg").html(res);
		   $("#errmsg").css("visibility", "visible");
	       }
	       else
		   window.location = "secret.php";
	   });
}