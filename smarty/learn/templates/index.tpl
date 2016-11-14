{%include file="header.tpl" filename="index.tpl"%}
<br>
{%$name%}
<br>
name: {%$info['name']%}
<br>
name: {%$info.name%}
<br>
age: {%$info['age']%}
<br>
age: {%$info.age%}
<br>
sex: {%$info['sex']%}
<br>
sex: {%$info.sex%}
<br>
{%$minfo['students']['name']%}
<br>
{%$minfo['teachers']['age']%}
<br>
<h3>变量调节器</h3>
<pre>
首字母大写 capitalize
{$articleTitle|capitalize}
</pre>
{%$articleTitle|capitalize%}

<pre>
字符串连接 cat
{$articleTitle|cat:"by liuwei"}
</pre>
{%$articleTitle|cat:" by liuwei"%}
<br>
{%$articleTitle|cat:" by liuwei":" 2016"%}
<br>
<pre>
时间变量调节器 date_format
{$time|date_format}
</pre>
{%$time|date_format%}
<br>
{%$time|date_format:"%H:%M:%S"%}
<br>
{%$time|date_format:"%A, %B %e, %Y"%}
<br>
{%$time|date_format:"%B %e, %Y"%}
<br>
{%$smarty.now|date_format:"%B %e, %Y"%}
<br>
<pre>
默认值 default
{$nullVal|default:"Smarty Variables Is Here"}
</pre>
{%$nullVal|default:"Smarty Variables Is Here"%}
<br>
<pre>
小写 lower
{$ABC|lower}
</pre>
{%$ABC|lower%}
<br>
<pre>
大写 upper
{$abc|upper}
</pre>
{%$abc|upper%}
<br>
<pre>
转码 escape
{$url|escape}
</pre>
{%$url|escape:"url"%}
<br>
<pre>
换行 nl2br
{$content|nl2br}
</pre>	
{%$content%}
<br>
{%$content|nl2br%}
<br>
<pre>
截取字符串 truncate
{$longString|truncate}
</pre>
{%$longString|truncate%}
<br>
{%$longString|truncate:30:"......"%}
<br>
{%$longString|truncate:10:"------"%}
<br>
{%if $temp gt 10%}
>10
{%else%}
other
{%/if%}
<br>
{%section name=item loop=$bookList%}

name: {%$bookList[item].name%}
<br>
price: {%$bookList[item].price%}
{%if $bookList[item].price eq 199%}
好贵
{%/if%}
<br>

{%/section%}

<br>

{%foreach item=book from=$bookList%}
name: {%$book.name%}
<br>
price: {%$book.price%}
{%if $book.price lt 199%}
便宜
{%/if%}
<br>
{%/foreach%}
<br>

{%foreach $bookList as $book%}	
name: {%$book.name%}
<br>
price: {%$book.price%}
<br>
{%/foreach%}
<br>	
{%foreach $bookNone as $book%}	
name: {%$book.name%}
price: {%$book.price%}
{%foreachelse%}
没有数据
{%/foreach%}
<br>
<ul id="list"></ul>

{%"Y-m-d"|date:$nowTime%}
<br>
{%'a'|str_replace:'A':$testStr%}
<br>
{%testFn p1='abc' p2='edf'%}
<br>
{%test width=20 height=30%}
<br>
{%$utime|test:'Y-m-d H:i:s'%}
<br>
<div id="timeArea"></div>
<script>
var jsonData = {%$json%};
var listStr = "";
var oUl = document.querySelector('#list');
jsonData.forEach(function(item,index,array){
	listStr+='<li>'+item.name+' / $'+item.price+'</li>';
});
oUl.innerHTML = listStr;


	
var oDiv = document.querySelector('#timeArea');

var fn = function(){
	//var time = new Date();
	
	oDiv.innerHTML = time;
}
setInterval(function(){
	fn();
}, 500);


</script>
</body>
</html>




