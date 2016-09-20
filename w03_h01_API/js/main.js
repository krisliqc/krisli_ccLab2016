var city = '';
var state = '';
var APIKey = 'b08e9f7fbd613265';

$(document).ready(function(){
	init();
});

var init = function () {
	$('#submit').click(function(e){
		e.preventDefault();
		setLocation();
	})
}

var setLocation = function(){
	city = $('.currentCity').val();
	state = $('.currentState').val();

	if(city == null || city == ''){
		alert("enter something for city");
		return;
	}
	getWeather();
}

var getWeather = function (){

	var myUrl = "http://api.wunderground.com/api/" + APIKey +"/astronomy/q/"+state+"/"+city+".json";
	// var myUrl = "http://api.wunderground.com/api/" + APIKey + "/hourly/q/"+state+"/"+city+".json";
	// var myUrl = "http://api.wunderground.com/api/" + APIKey + "/geolookup/conditions/q/"+state+"/"+city+".json";

	$.ajax({
		url: myUrl,
		dataType: "jsonp", //jsonp vs. json - 
		success: function (response) {
			console.log(response);
			loadWeather(response);
		}
	})
}

var loadWeather = function(response){
	if(response.response.error){
		alert(response.response.error.description);
		return;
	}

	var riseHour = response.sun_phase.sunrise.hour;
	var setHour = response.sun_phase.sunset.hour;
	var moon = response.moon_phase.percentIlluminated;
	console.log("rise hour is " +riseHour);
	console.log("set hour is " +setHour);
	console.log("moon brightness is " +moon)

	// var heightValue = riseHour + "0px"
	// console.log("height value is " + heightValue); 
	var widthStart = riseHour *45 + 80 + "px";
	var widthEnd = setHour *45 - riseHour *50 + "px";
	var moonLight = moon * 0.01;
	console.log("moonLight is "+moonLight);

	// document.body.style.backgroundColor = "grey";
	// document.getElementById("one").style.height = heightValue;
	document.getElementById("one").style.left = widthStart;
	document.getElementById("one").style.width = widthEnd;

	document.getElementById("moon").style.opacity = moonLight;
	document.getElementById("moonlight").innerHTML = "brightness: "+ moonLight;

}


