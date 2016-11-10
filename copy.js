var fs = require( 'fs' );
    


var copy = function( srcfile, dstfile ){
    
    // 创建读取流
    readable = fs.createReadStream( srcfile );
    // 创建写入流
    writable = fs.createWriteStream( dstfile );   
    // 通过管道来传输流
    readable.pipe( writable );
               
           
};

//copy('1.txt','2.txt');

var readline = require("readline");
var rl = readline.createInterface({
	    input:  process.stdin,
	    output: process.stdout
});

rl.setPrompt("Linux Shell > ");
rl.prompt();
	rl.on('line',function(input){
	    var shell = input.trim();
	    switch(shell){
	        case '-help':
	            console.log("\n****************************************\n"+"\n-h          ----      使用方法\n-i          ----      命令功能\n-copy       ----      拷贝\n-exit       ----      退出\n"+"\n****************************************\n");
	            break;

	        case '-i':
	            console.log("使用 copy 命名实现文件拷贝");
	            break;

	        case '-h':
	            console.log("使用方法 copy srcfile distfile");
	            break;
	        case 'exit':
	            console.log("\n 程序已经退出！ \n");
	            rl.close();
	            process.exit(0);
	            break;
	        default:
	        	console.log(shell);
	        	if(shell.indexOf('copy')===-1){
	        		   console.log("\n****************************************************************\n"+
	            			"*    Linux Shell Demo！输入'-help'查看更多帮助信息！    *"+
	            			"\n****************************************************************\n"
	            );

	        	}else{
	        		var param = shell.split(' ');
		        	var srcfile = param[1];
		        	var distfile = param[2];
		        	copy(srcfile,distfile);
		        	console.log("拷贝成功！");

	        	}
	        	
	        	// console.log(param);
	         
	    }
rl.prompt();
});

