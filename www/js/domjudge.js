function XMLHttpHandle()
{
	var ajaxRequest;
	try {
		ajaxRequest = new XMLHttpRequest();
	} catch (e) {
		try {
			ajaxRequest = new ActiveXObject("MSXML2.XMLHTTP.3.0");
		} catch (e) {
			ajaxRequest = false;
		}
	}
	return ajaxRequest;
}

function updateClarifications(ajaxtitle)
{
	var handle = XMLHttpHandle();
	if (!handle) {
		return;
	}
	handle.onreadystatechange = function() {
		if (handle.readyState == 4) {
			var elem = document.getElementById('menu_clarifications');
			var cnew = handle.responseText;
			var newstr = ''
			if (cnew == 0) {
				elem.className = null;
			} else {
				newstr = ' ('+cnew+' new)';
				elem.className = 'new';
			}
			elem.innerHTML = 'clarifications' + newstr;
			if(ajaxtitle) {
				document.title = ajaxtitle + newstr;
			}
		}
	}
	handle.open("GET", "update_clarifications.php", true);
	handle.send(null);
}

// make corresponding testcase description editable
function editTcDesc(descid)
{
	var node = document.getElementById('tcdesc_' + descid);
	node.parentNode.setAttribute('onclick', '');
	node.parentNode.removeChild(node.nextSibling);
	node.style.display = 'block';
	node.setAttribute('name', 'description[' + descid + ']');
}

// hides edit field if javascript is enabled
function hideTcDescEdit(descid)
{
	var node = document.getElementById('tcdesc_' + descid);
	node.style.display = 'none';
	node.setAttribute('name', 'invalid');

	var span = document.createElement('span');
	span.innerHTML = node.innerHTML;
	node.parentNode.appendChild(span);
}

// Autodetection of problem, language in websubmit
function detectProblemLanguage(filename)
{
	var addfile = document.getElementById("addfile");
	if ( addfile ) addfile.disabled = false;

	var parts = filename.toLowerCase().split('.').reverse();
	if ( parts.length < 2 ) return;

	// problem ID
	var elt=document.getElementById('probid');
	for (i=0;i<elt.length;i++) {
		if ( elt.options[i].value.toLowerCase() == parts[1] ) {
			elt.selectedIndex = i;
		}
	}

	// language ID
	var elt=document.getElementById('langid');
	var langid = getMainExtension(parts[0]);
	for (i=0;i<elt.length;i++) {
		if ( elt.options[i].value == langid ) {
			elt.selectedIndex = i;
		}
	}

}

function checkUploadForm()
{
	var langelt = document.getElementById("langid");
	var language = langelt.options[langelt.selectedIndex].value;
	var languagetxt = langelt.options[langelt.selectedIndex].text;
	var filebut = document.getElementById("codebutton");
	var fileelt = document.getElementById("maincode");
	var filename = fileelt.value;
	var probelt = document.getElementById("probid");
	var problem = probelt.options[probelt.selectedIndex].value;
	var problemtxt = probelt.options[probelt.selectedIndex].text + " - " + getProbDescription(probelt.options[probelt.selectedIndex].text);
	var auxfiles = document.getElementsByName("code[]");

	var error = false;
	langelt.className = probelt.className = filebut.className = "";
	if ( language == "" ) {
		langelt.focus();
		langelt.className = "errorfield";
		error = true;
	}
	if ( problem == "" ) {
		probelt.focus();
		probelt.className = "errorfield";
		error = true;
	}
	if ( filename == "" ) {
		filebut.className = "errorfield";
		return false;
	}

	if ( error ) {
		return false;
	} else {
		var auxfileno = 0;
		// start at one; skip maincode file field
		for (var i = 1; i < auxfiles.length; i++) {
			if (auxfiles[i].value != "" ) {
				auxfileno++;
			}
		}
		var extrafiles = '';
		if ( auxfileno > 0 ) {
			extrafiles = "Additional source files: " + auxfileno + '\n';
		}
		var question =
			'Main source file: ' + filename + '\n' +
			extrafiles + '\n' +
			'Problem: ' + problemtxt + '\n'+
			'Language: ' + languagetxt + '\n' +
			'\nMake submission?';
		return confirm (question);
	}

}

function resetUploadForm(refreshtime) {
	var filebut = document.getElementById("codebutton");
	var addfile = document.getElementById("addfile");
	var auxfiles = document.getElementById("auxfiles");
	var selecttext = "Select file...";
	filebut.value = selecttext;
	addfile.disabled = true;
	auxfiles.innerHTML = "";
	doReload = true;
	setTimeout('reloadPage()', refreshtime * 1000);
}

var W3CDOM = (document.createElement && document.getElementsByTagName);

var doReload = true;

function reloadPage()
{
	// interval is in seconds
	if (doReload) {
		location.reload(true);
	}
}

function initReload(refreshtime)
{
	// interval is in seconds
	setTimeout('reloadPage()', refreshtime * 1000);
}

function initFileUploads() {
	$("#codebutton").filestyle({classInput: "input-small"});
	var x = document.getElementsByTagName('input');

	for (var i=0;i<x.length;i++) {
		if (x[i].type != 'file') continue;
		if (x[i].parentNode.className != 'fileinputs') continue;

		// stop refresh when clicking a button.
		x[i].onclick = function() { doReload = false; }
		x[i].onchange = x[i].onmouseout = function () {
				var filename = this.value;
				// Opera prepends a fake fs path: C:\fakepath\. Strip that.
				var fake = "fakepath\\";
				if ( filename.indexOf(fake) >= 0 ) {
					filename = filename.substr(filename.lastIndexOf(fake)+fake.length);
				}
				// some other browsers (Konqueror at least) may prepend the full FS path
				if ( filename.indexOf(File.separator) >= 0 ) {
					filename = filename.substr(filename.lastIndexOf(File.separator)+1);
				}
				detectProblemLanguage(filename);
		}
	}
}

function collapse(x){
	var oTemp=document.getElementById("detail"+x);
	if (oTemp.style.display=="none") {
		oTemp.style.display="block";
	} else {
		oTemp.style.display="none";
	}
}

function addFileUpload() {
	var span = document.createElement('span');
	span.className = 'upload_btn';
	document.getElementById('auxfiles').appendChild( span );

	var input = document.createElement('input');
	input.type = 'file';
	input.name = 'code[]';
	input.size = '50';
	input.multiple = "multiple";
	span.appendChild( input );

	var br = document.createElement('br');
	document.getElementById('auxfiles').appendChild( br );

	// Reset all input file
	$('input[type="file"]').filestyle({
		classInput: "input-medium",
		buttonText: 'Upload'
	});
}

function togglelastruns() {
	var names = {'lastruntime':0, 'lastresult':1};
	for (var name in names) {
		cells = document.getElementsByName(name);
		for (i = 0; i < cells.length; i++) {
			cells[i].style.display = (cells[i].style.display == 'none') ? 'table-cell' : 'none';
		}
	}
}

function toggleOutput(divId) {
	$("#" + divId).fadeToggle('slow');
}

function updateClock() {
	curtime = initial+offset;
	date.setTime(curtime*1000);

	var fmt = "";
	if (curtime >= starttime && curtime < endtime ) {
		var left = endtime - curtime;
		var what = "time left: ";
	} else if (curtime >= activatetime && curtime < starttime ) {
		var left = starttime - curtime;
		var what = "time to start: ";
	} else {
		var left = 0;
		var what = "";
	}

	if ( left ) {
		if ( left > 24*60*60 ) {
			d = Math.floor(left/(24*60*60));
			fmt += d + "d ";
			left -= d * 24*60*60;
		}
		if ( left > 60*60 ) {
			h = Math.floor(left/(60*60));
			fmt += h + ":";
			left -= h * 60*60;
		} 
		m = Math.floor(left/60);
		if ( m < 10 ) { fmt += "0"; }
		fmt += m + ":";
		left -= m * 60;
		if ( left < 10 ) { fmt += "0"; }
		fmt += left;
	}

	timecurelt.innerHTML = date.toString().replace(/(\w{3})\ (\w{3})\ (\d{2})\ (\d{4})\ (\d{2}:\d{2}:\d{2}).*\((\w+)\)/, "$1 $3 $2 $4 $5 $6");
	timeleftelt.innerHTML = what + fmt;
	offset++;
}