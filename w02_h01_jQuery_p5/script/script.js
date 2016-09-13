var xmap, ymap;
var x,y;
var r, g, b;
var rNew, gNew, bNew; 
var posX, posY;

document.addEventListener("click", pickColor);

document.getElementById("bri").addEventListener("mousedown", pickBri);

function pickBri (){
	// var brightness = 255;
	var brightness = prompt("enter a number from 0 to 255");
	console.log(brightness);

	// $("bri").innerHTML = "BRIGHTNESSes";
	document.getElementById("bri").innerHTML = "BRIGHTNESS: " + brightness;

}

function showPos (event){
var x = event.clientX*40/1100;
var y = (event.clientY-100)*25/800;
	// var rNew = xmapjs *6;
	// var gNew = ymapjs *10;
	// var bNew = 100;

}

function pickColor (){
	// document.getElementById("colorOn").style.backgroundColor = "rgb(rNew,gNew,bNew)";

	// $("gValue").innerHTML = "G: " + g;

	document.getElementById("rValue").innerHTML = "R: " + r;
	document.getElementById("gValue").innerHTML = "G: " + g;
	document.getElementById("bValue").innerHTML = "B: " + 100;
	console.log("rgb input");
	console.log("rNew = " + rNew);
	console.log("gNew = " + gNew);
	console.log("bNew = " + bNew);

	console.log(x);
	console.log(y);
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
	// var r = xmap *6 -255 + brightness;
	// var g = ymap *10 -255 + brightness;
	// var b = 100 -255 + brightness;

	var r = xmap *6;
	var g = ymap *10;
	var b = 100;
	fill(r,g,b);
	stroke(255-mouseX/3);
	strokeWeight(5);
	rect(mouseX,mouseY,75,75);

	// console.log("r = " + r);
	// console.log("g = " + g);
	// console.log("b = " + b);
}

