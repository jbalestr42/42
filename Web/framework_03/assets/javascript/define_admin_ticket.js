function define_admin_ticket(id) {
	for (var i = 0; i < 128; i++) {
		if($('.define_admin_' + i))
		{
			if (i != id)
				$(".define_admin_" + i).slideUp("fast");
		}
		else
			break ;
	}
	$('.define_admin_' + id).slideToggle("fast");
}