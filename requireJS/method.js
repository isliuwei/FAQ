define(['ulti'],function(ulti){

	
	function sortArray(args)
	{

		return ulti.isArray(args)?args.sort(function(a,b){return a-b;}):"!Error Not Array!";
	}


	return sortArray;







});