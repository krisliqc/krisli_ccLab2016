document.addEventListener('DOMContentLoaded',function(){
	var colorPool = ["#fcf","#ccf","#ffc"];
	var seconds = 0;
	var temp;

	var parentDiv = document.getElementsByClassName("blockContainer");
	var div1 = document.getElementById("div1");
	var div2 = document.getElementById("div2");
	var div3 = document.getElementById("div3");

	div1.style.backgroundColor = "#000";
	div2.style.backgroundColor = "#000";
	div3.style.backgroundColor = "#000";

	setInterval(function(){
		seconds+=1;
		// console.log(seconds);
		// parentDiv[0].style.transform = "rotate(90deg)";
		// parentDiv[0].style.webkitTransform = "rotate(90deg)";

		parentDiv[0].style.transform = "rotate(" + seconds*90 + "deg)";
		parentDiv[0].style.webkitTransform = "rotate(" + seconds*90 + "deg)";

		div1.style.backgroundColor = colorPool[0];
		div2.style.backgroundColor = colorPool[1];
		div3.style.backgroundColor = colorPool[2];

		temp = colorPool[0];
		colorPool.shift();  //from right to left, so remove the last element and shift everything forward
		colorPool.push(temp);

		//push with shift and pop with unshift

	},1000); //first argument is a function, second argument is an interval

})


// var student = {
// 	firstName: "Sven";
// 	lastName: "T.";
// 	param1: 2;
// };  // this is declaring a variable(object) which is more complex

// student.firstName = "John";

// var animals = ["ani1", "ani2", "ani3"]; //this is an array