<?php
/* Smarty version 3.1.29, created on 2016-11-14 11:40:04
  from "/Applications/XAMPP/xamppfiles/htdocs/smarty/learn/templates/index.tpl" */

if ($_smarty_tpl->smarty->ext->_validateCompiled->decodeProperties($_smarty_tpl, array (
  'has_nocache_code' => false,
  'version' => '3.1.29',
  'unifunc' => 'content_5829948418d8a7_57545300',
  'file_dependency' => 
  array (
    'fa21ff8cbcfb7627591754c652272b86cb3e57cd' => 
    array (
      0 => '/Applications/XAMPP/xamppfiles/htdocs/smarty/learn/templates/index.tpl',
      1 => 1479120001,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
    'file:header.tpl' => 1,
  ),
),false)) {
function content_5829948418d8a7_57545300 ($_smarty_tpl) {
if (!is_callable('smarty_modifier_capitalize')) require_once '/Applications/XAMPP/xamppfiles/htdocs/smarty/libs/smarty/plugins/modifier.capitalize.php';
if (!is_callable('smarty_modifier_date_format')) require_once '/Applications/XAMPP/xamppfiles/htdocs/smarty/libs/smarty/plugins/modifier.date_format.php';
if (!is_callable('smarty_modifier_truncate')) require_once '/Applications/XAMPP/xamppfiles/htdocs/smarty/libs/smarty/plugins/modifier.truncate.php';
if (!is_callable('smarty_function_test')) require_once '/Applications/XAMPP/xamppfiles/htdocs/smarty/libs/smarty/plugins/function.test.php';
if (!is_callable('smarty_modifier_test')) require_once '/Applications/XAMPP/xamppfiles/htdocs/smarty/libs/smarty/plugins/modifier.test.php';
$_smarty_tpl->smarty->ext->_subtemplate->render($_smarty_tpl, "file:header.tpl", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 0, $_smarty_tpl->cache_lifetime, array('filename'=>"index.tpl"), 0, false);
?>

<br>
<?php echo $_smarty_tpl->tpl_vars['name']->value;?>

<br>
name: <?php echo $_smarty_tpl->tpl_vars['info']->value['name'];?>

<br>
name: <?php echo $_smarty_tpl->tpl_vars['info']->value['name'];?>

<br>
age: <?php echo $_smarty_tpl->tpl_vars['info']->value['age'];?>

<br>
age: <?php echo $_smarty_tpl->tpl_vars['info']->value['age'];?>

<br>
sex: <?php echo $_smarty_tpl->tpl_vars['info']->value['sex'];?>

<br>
sex: <?php echo $_smarty_tpl->tpl_vars['info']->value['sex'];?>

<br>
<?php echo $_smarty_tpl->tpl_vars['minfo']->value['students']['name'];?>

<br>
<?php echo $_smarty_tpl->tpl_vars['minfo']->value['teachers']['age'];?>

<br>
<h3>变量调节器</h3>
<pre>
首字母大写 capitalize
{$articleTitle|capitalize}
</pre>
<?php echo smarty_modifier_capitalize($_smarty_tpl->tpl_vars['articleTitle']->value);?>


<pre>
字符串连接 cat
{$articleTitle|cat:"by liuwei"}
</pre>
<?php echo ($_smarty_tpl->tpl_vars['articleTitle']->value).(" by liuwei");?>

<br>
<?php echo ($_smarty_tpl->tpl_vars['articleTitle']->value).(" by liuwei").(" 2016");?>

<br>
<pre>
时间变量调节器 date_format
{$time|date_format}
</pre>
<?php echo smarty_modifier_date_format($_smarty_tpl->tpl_vars['time']->value);?>

<br>
<?php echo smarty_modifier_date_format($_smarty_tpl->tpl_vars['time']->value,"%H:%M:%S");?>

<br>
<?php echo smarty_modifier_date_format($_smarty_tpl->tpl_vars['time']->value,"%A, %B %e, %Y");?>

<br>
<?php echo smarty_modifier_date_format($_smarty_tpl->tpl_vars['time']->value,"%B %e, %Y");?>

<br>
<?php echo smarty_modifier_date_format(time(),"%B %e, %Y");?>

<br>
<pre>
默认值 default
{$nullVal|default:"Smarty Variables Is Here"}
</pre>
<?php echo (($tmp = @$_smarty_tpl->tpl_vars['nullVal']->value)===null||$tmp==='' ? "Smarty Variables Is Here" : $tmp);?>

<br>
<pre>
小写 lower
{$ABC|lower}
</pre>
<?php echo mb_strtolower($_smarty_tpl->tpl_vars['ABC']->value, 'UTF-8');?>

<br>
<pre>
大写 upper
{$abc|upper}
</pre>
<?php echo mb_strtoupper($_smarty_tpl->tpl_vars['abc']->value, 'UTF-8');?>

<br>
<pre>
转码 escape
{$url|escape}
</pre>
<?php echo rawurlencode($_smarty_tpl->tpl_vars['url']->value);?>

<br>
<pre>
换行 nl2br
{$content|nl2br}
</pre>	
<?php echo $_smarty_tpl->tpl_vars['content']->value;?>

<br>
<?php echo nl2br($_smarty_tpl->tpl_vars['content']->value);?>

<br>
<pre>
截取字符串 truncate
{$longString|truncate}
</pre>
<?php echo smarty_modifier_truncate($_smarty_tpl->tpl_vars['longString']->value);?>

<br>
<?php echo smarty_modifier_truncate($_smarty_tpl->tpl_vars['longString']->value,30,"......");?>

<br>
<?php echo smarty_modifier_truncate($_smarty_tpl->tpl_vars['longString']->value,10,"------");?>

<br>
<?php if ($_smarty_tpl->tpl_vars['temp']->value > 10) {?>
>10
<?php } else { ?>
other
<?php }?>
<br>
<?php
$__section_item_0_saved = isset($_smarty_tpl->tpl_vars['__smarty_section_item']) ? $_smarty_tpl->tpl_vars['__smarty_section_item'] : false;
$__section_item_0_loop = (is_array(@$_loop=$_smarty_tpl->tpl_vars['bookList']->value) ? count($_loop) : max(0, (int) $_loop));
$__section_item_0_total = $__section_item_0_loop;
$_smarty_tpl->tpl_vars['__smarty_section_item'] = new Smarty_Variable(array());
if ($__section_item_0_total != 0) {
for ($__section_item_0_iteration = 1, $_smarty_tpl->tpl_vars['__smarty_section_item']->value['index'] = 0; $__section_item_0_iteration <= $__section_item_0_total; $__section_item_0_iteration++, $_smarty_tpl->tpl_vars['__smarty_section_item']->value['index']++){
?>

name: <?php echo $_smarty_tpl->tpl_vars['bookList']->value[(isset($_smarty_tpl->tpl_vars['__smarty_section_item']->value['index']) ? $_smarty_tpl->tpl_vars['__smarty_section_item']->value['index'] : null)]['name'];?>

<br>
price: <?php echo $_smarty_tpl->tpl_vars['bookList']->value[(isset($_smarty_tpl->tpl_vars['__smarty_section_item']->value['index']) ? $_smarty_tpl->tpl_vars['__smarty_section_item']->value['index'] : null)]['price'];?>

<?php if ($_smarty_tpl->tpl_vars['bookList']->value[(isset($_smarty_tpl->tpl_vars['__smarty_section_item']->value['index']) ? $_smarty_tpl->tpl_vars['__smarty_section_item']->value['index'] : null)]['price'] == 199) {?>
好贵
<?php }?>
<br>

<?php
}
}
if ($__section_item_0_saved) {
$_smarty_tpl->tpl_vars['__smarty_section_item'] = $__section_item_0_saved;
}
?>

<br>

<?php
$_from = $_smarty_tpl->tpl_vars['bookList']->value;
if (!is_array($_from) && !is_object($_from)) {
settype($_from, 'array');
}
$__foreach_book_0_saved_item = isset($_smarty_tpl->tpl_vars['book']) ? $_smarty_tpl->tpl_vars['book'] : false;
$_smarty_tpl->tpl_vars['book'] = new Smarty_Variable();
$_smarty_tpl->tpl_vars['book']->_loop = false;
foreach ($_from as $_smarty_tpl->tpl_vars['book']->value) {
$_smarty_tpl->tpl_vars['book']->_loop = true;
$__foreach_book_0_saved_local_item = $_smarty_tpl->tpl_vars['book'];
?>
name: <?php echo $_smarty_tpl->tpl_vars['book']->value['name'];?>

<br>
price: <?php echo $_smarty_tpl->tpl_vars['book']->value['price'];?>

<?php if ($_smarty_tpl->tpl_vars['book']->value['price'] < 199) {?>
便宜
<?php }?>
<br>
<?php
$_smarty_tpl->tpl_vars['book'] = $__foreach_book_0_saved_local_item;
}
if ($__foreach_book_0_saved_item) {
$_smarty_tpl->tpl_vars['book'] = $__foreach_book_0_saved_item;
}
?>
<br>

<?php
$_from = $_smarty_tpl->tpl_vars['bookList']->value;
if (!is_array($_from) && !is_object($_from)) {
settype($_from, 'array');
}
$__foreach_book_1_saved_item = isset($_smarty_tpl->tpl_vars['book']) ? $_smarty_tpl->tpl_vars['book'] : false;
$_smarty_tpl->tpl_vars['book'] = new Smarty_Variable();
$_smarty_tpl->tpl_vars['book']->_loop = false;
foreach ($_from as $_smarty_tpl->tpl_vars['book']->value) {
$_smarty_tpl->tpl_vars['book']->_loop = true;
$__foreach_book_1_saved_local_item = $_smarty_tpl->tpl_vars['book'];
?>	
name: <?php echo $_smarty_tpl->tpl_vars['book']->value['name'];?>

<br>
price: <?php echo $_smarty_tpl->tpl_vars['book']->value['price'];?>

<br>
<?php
$_smarty_tpl->tpl_vars['book'] = $__foreach_book_1_saved_local_item;
}
if ($__foreach_book_1_saved_item) {
$_smarty_tpl->tpl_vars['book'] = $__foreach_book_1_saved_item;
}
?>
<br>	
<?php
$_from = $_smarty_tpl->tpl_vars['bookNone']->value;
if (!is_array($_from) && !is_object($_from)) {
settype($_from, 'array');
}
$__foreach_book_2_saved_item = isset($_smarty_tpl->tpl_vars['book']) ? $_smarty_tpl->tpl_vars['book'] : false;
$_smarty_tpl->tpl_vars['book'] = new Smarty_Variable();
$_smarty_tpl->tpl_vars['book']->_loop = false;
foreach ($_from as $_smarty_tpl->tpl_vars['book']->value) {
$_smarty_tpl->tpl_vars['book']->_loop = true;
$__foreach_book_2_saved_local_item = $_smarty_tpl->tpl_vars['book'];
?>	
name: <?php echo $_smarty_tpl->tpl_vars['book']->value['name'];?>

price: <?php echo $_smarty_tpl->tpl_vars['book']->value['price'];?>

<?php
$_smarty_tpl->tpl_vars['book'] = $__foreach_book_2_saved_local_item;
}
if (!$_smarty_tpl->tpl_vars['book']->_loop) {
?>
没有数据
<?php
}
if ($__foreach_book_2_saved_item) {
$_smarty_tpl->tpl_vars['book'] = $__foreach_book_2_saved_item;
}
?>
<br>
<ul id="list"></ul>

<?php echo date("Y-m-d",$_smarty_tpl->tpl_vars['nowTime']->value);?>

<br>
<?php echo str_replace('a','A',$_smarty_tpl->tpl_vars['testStr']->value);?>

<br>
<?php echo testFn(array('p1'=>'abc','p2'=>'edf'),$_smarty_tpl);?>

<br>
<?php echo smarty_function_test(array('width'=>20,'height'=>30),$_smarty_tpl);?>

<br>
<?php echo smarty_modifier_test($_smarty_tpl->tpl_vars['utime']->value,'Y-m-d H:i:s');?>

<br>
<div id="timeArea"></div>
<?php echo '<script'; ?>
>
var jsonData = <?php echo $_smarty_tpl->tpl_vars['json']->value;?>
;
var listStr = "";
var oUl = document.querySelector('#list');
jsonData.forEach(function(item,index,array){
	listStr+='<li>'+item.name+' / $'+item.price+'</li>';
});
oUl.innerHTML = listStr;


	
var oDiv = document.querySelector('#timeArea');

var fn = function(){
	//var time = new Date();
	var time = "'"+<?php echo smarty_modifier_date_format($_smarty_tpl->tpl_vars['time']->value);?>
+"'";
	oDiv.innerHTML = time;
}
setInterval(function(){
	fn();
}, 500);


<?php echo '</script'; ?>
>
</body>
</html>




<?php }
}
