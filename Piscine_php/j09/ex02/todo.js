window.onload = initCookies;

function initCookies() {
	var cookies = document.cookie;
	var tab = cookies.split(";");
	for (t in tab)
	{
		if (tab[t].indexOf("div") != -1)
			createDiv(tab[t].split("=")[1], false);
	}
}

function deleteTodo(event) {
	var res = confirm('are you sure ?');
	if (res)
	{
		var parent = document.getElementById('ft_list');
		parent.removeChild(event.target);
		document.cookie = "div" + event.target.textContent + "=; expires=Thu, 01 Jan 1970 00:00:00 GMT";
	}
}

function createDiv(text, create) {
	var parent = document.getElementById('ft_list');
	var div = document.createElement('div');
	div.textContent = text;
	div.onclick = deleteTodo;
	parent.insertBefore(div, parent.firstChild);
	if (create == true)
		document.cookie = "div" + text + "=" + text;
}

function PromptMessage() {
	var val = prompt("Saisissez votre texte :", "")
		if (val != null)
			createDiv(val, true);
}
