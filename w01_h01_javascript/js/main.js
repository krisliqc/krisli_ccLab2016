var buttonY = document.getElementsByClassName("yes");

for (var i = 0; i < 5; i++){
		buttonY[i].addEventListener("mousedown", move);
	}

function move (){
	var select = document.getElementById("r1");
	select.style.display = "none";

	var poolY = document.getElementById("y");

	var yRes = document.createElement("div");
	yRes.id = "newImage";
	poolY.appendChild(yRes);
}


// function move (){
// 	//select the on click item
// 	//select its parent element
// 	//var selected = 
// 	var parentDiv = selected.parentNode;
// 	parentDiv.style.display = "none";


// 	var poolY = document.getElementById("y");

// 	var yRes = document.createElement("img");
// 	yRes.src = "../img/"+img1+".jpg"
// 	poolY.appendChild(yRes);

// }


var buttonN = document.getElementsByClassName("no");

for (var i = 0; i < 5; i++){
		buttonN[i].addEventListener("mousedown", move2);
	}

function move2 (){
	var select = document.getElementById("r2");
	select.style.display = "none";

	var poolN = document.getElementById("n");

	var nRes = document.createElement("div");
	nRes.id = "newImage2";
	poolN.appendChild(nRes);
}
