var xmap, ymap;

document.addEventListener("click", pickColor);

document.getElementById("bri").addEventListener("mousedown", pickBri);

function pickBri (){
	var brightness = prompt("enter a number from 0 to 255");

	// var t = document.createTextNode(brightness);
	// $("bright").appendChild(t);
}

function pickColor (){
	// var select = document.getElementById("colorOn");
	// select.style.display = "none";

	//select div with id: colorOn and hide it
	// $("colorOn").remove();

	document.getElementById("colorOn").style.backgroundColor = "rgb(mouseX,mouseY,100)";
	// $("colorOn").css("background-color","rgb(200,150,100)";

		// color example
		// div {
  		//   background-color: rgb(0, 191, 255);
  		//   color: rgb(255, 255, 255);
		// }
}

function setup() {
createCanvas(1100,800);
}

function draw() {
	//making the color grid

	for(i=0; i < 40; i++){
		for (j=0;j<25; j++){
			noStroke();
			// ymap = map(0,mouseY,0,255);
			fill(i*6,j*9,100);

			// add var brightness to each of the r,g,b value

			rect(i*width/40,j*height/25,width/40,height/25);
		}
	}

	//showing the current grid color
	var xmap = map(mouseX,0,1100,0,40);
	var ymap = map(mouseY,0,800,0,25);
	fill(xmap*6,ymap*10,100);
	stroke(255-mouseX/3);
	strokeWeight(5);
	rect(mouseX,mouseY,75,75);
}

