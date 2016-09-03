var ulti = require("./ulti.js");

exports.uniqueArray = function(args)
{
	if(ulti.isArray(args))
	{
		
		var uniqueArr = [];
		for(var i=0; i<args.length; i++)
		{
			for(var j=i+1; j<args.length; j++)
			{
				if(args[j] === args[i])
				{
					j = ++i;
				}
			}

			uniqueArr.push(args[i]);
		}
		return uniqueArr;

		
		
		
		/* indexOf方法
		return args.filter(function(item,index,array){
			return array.indexOf(item) === index;
		});
		*/


		// var hash = {};
		// var uniqueArr = [];
		/* hash方法
		for(var i=0; i<args.length; i++)
		{
			if(!hash[args[i]])
			{
				hash[args[i]] = true;
				uniqueArr.push(args[i]);
			}
		}

		return uniqueArr;
		
		*/
		/* hash方法 + Iterator方法
		return args.filter(function(item,index,array){
			return hash.hasOwnProperty(item)?false:(hash[item]=true);
		});
		*/

		/*
		var hash = {};
		var uniqueArr = [];

		for (var i=0; i<args.length; i++) 
		{
		    var item = args[i];
		    var key = typeof(item) + item;
		    if(hash[key] !== 1) 
		    {
		      uniqueArr.push(item);
		      hash[key] = 1;
		    }
		}

  		return uniqueArr;
  		*/

		
		


	}
	else
	{
		console.log("错误");
	}


}