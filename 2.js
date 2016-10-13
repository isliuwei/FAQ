var EventEmitter = require('events').EventEmitter;
var emitter = new EventEmitter;



emitter.on('event1',(mess)=>{
	console.log(mess);
});



emitter.emit('event1','I am a message!');