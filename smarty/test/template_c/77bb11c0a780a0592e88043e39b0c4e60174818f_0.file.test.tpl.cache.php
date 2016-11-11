<?php
/* Smarty version 3.1.29, created on 2016-06-05 13:37:03
  from "/Applications/XAMPP/xamppfiles/htdocs/smarty/test/tpl/test.tpl" */

if ($_smarty_tpl->smarty->ext->_validateCompiled->decodeProperties($_smarty_tpl, array (
  'has_nocache_code' => false,
  'version' => '3.1.29',
  'unifunc' => 'content_57540edfad0f29_39355473',
  'file_dependency' => 
  array (
    '77bb11c0a780a0592e88043e39b0c4e60174818f' => 
    array (
      0 => '/Applications/XAMPP/xamppfiles/htdocs/smarty/test/tpl/test.tpl',
      1 => 1465126621,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
    'file:header.tpl' => 1,
  ),
),false)) {
function content_57540edfad0f29_39355473 ($_smarty_tpl) {
if (!is_callable('smarty_modifier_capitalize')) require_once '/Applications/XAMPP/xamppfiles/htdocs/smarty/smarty/plugins/modifier.capitalize.php';
if (!is_callable('smarty_modifier_date_format')) require_once '/Applications/XAMPP/xamppfiles/htdocs/smarty/smarty/plugins/modifier.date_format.php';
$_smarty_tpl->compiled->nocache_hash = '151743148857540edfa77968_86605679';
?>
<div style="background: #aaa; width: 500px; height: 200px;line-height: 200px;text-align: center;">
	<?php $_smarty_tpl->smarty->ext->_subtemplate->render($_smarty_tpl, "file:header.tpl", $_smarty_tpl->cache_id, $_smarty_tpl->compile_id, 9999, $_smarty_tpl->cache_lifetime, array('sitename'=>"isliuwei.com"), 0, false);
?>

</div>

<br>
<?php echo (($tmp = @$_smarty_tpl->tpl_vars['title']->value)===null||$tmp==='' ? "这里是标题" : $tmp);?>

<br />	
<?php echo smarty_modifier_capitalize($_smarty_tpl->tpl_vars['articletitle']->value);?>

<br />
<?php echo (smarty_modifier_capitalize($_smarty_tpl->tpl_vars['articletitle']->value)).(" Smarty.").("nihao");?>

<br />
<?php echo (smarty_modifier_date_format($_smarty_tpl->tpl_vars['time']->value,"%H:%M:%S")).(" 格林威治时间 ");?>

<br />
<?php echo smarty_modifier_date_format($_smarty_tpl->tpl_vars['time']->value,"%B %e, %Y");?>

<br />
<?php echo smarty_modifier_date_format($_smarty_tpl->tpl_vars['time']->value,"%B %e, %Y %H:%M:%S");?>

<br />
<?php echo rawurlencode($_smarty_tpl->tpl_vars['url']->value);?>

<br />
<?php echo htmlspecialchars($_smarty_tpl->tpl_vars['html']->value, ENT_QUOTES, 'UTF-8', true);?>

<br />
<?php echo $_smarty_tpl->tpl_vars['javascript1']->value;?>

<br />
<?php echo strtr($_smarty_tpl->tpl_vars['javascript2']->value, array("\\" => "\\\\", "'" => "\\'", "\"" => "\\\"", "\r" => "\\r", "\n" => "\\n", "</" => "<\/" ));?>

<br />
<?php echo nl2br($_smarty_tpl->tpl_vars['content']->value);?>

<br />
<?php if ($_smarty_tpl->tpl_vars['name1']->value == 'admin') {?>
welcome <?php echo $_smarty_tpl->tpl_vars['name1']->value;?>
;
<?php }?>
<br />
<?php if ($_smarty_tpl->tpl_vars['name2']->value == 'admin') {?>
welcome <?php echo $_smarty_tpl->tpl_vars['name2']->value;?>
;
<?php } else { ?>
welcome <?php echo $_smarty_tpl->tpl_vars['name2']->value;?>
;
<?php }?>
<br />
<?php if ($_smarty_tpl->tpl_vars['name3']->value == 'admin') {?>
welcome <?php echo $_smarty_tpl->tpl_vars['name3']->value;?>
;
<?php } elseif ($_smarty_tpl->tpl_vars['name3']->value == 'guest') {?>
welcome <?php echo $_smarty_tpl->tpl_vars['name3']->value;?>
;
<?php } else { ?>
welcome <?php echo $_smarty_tpl->tpl_vars['name3']->value;?>
;
<?php }?>
<br />
<table border='1'>
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
		<tr>
			<td><?php echo $_smarty_tpl->tpl_vars['book']->value['name'];?>
</td>
			<td><?php echo ($_smarty_tpl->tpl_vars['book']->value['price']).("￥");?>
</td>
		</tr>
	<?php
$_smarty_tpl->tpl_vars['book'] = $__foreach_book_0_saved_local_item;
}
if ($__foreach_book_0_saved_item) {
$_smarty_tpl->tpl_vars['book'] = $__foreach_book_0_saved_item;
}
?>
</table>

<table border='1'>
	<?php
$_from = $_smarty_tpl->tpl_vars['personList']->value;
if (!is_array($_from) && !is_object($_from)) {
settype($_from, 'array');
}
$__foreach_person_1_saved_item = isset($_smarty_tpl->tpl_vars['person']) ? $_smarty_tpl->tpl_vars['person'] : false;
$_smarty_tpl->tpl_vars['person'] = new Smarty_Variable();
$_smarty_tpl->tpl_vars['person']->_loop = false;
foreach ($_from as $_smarty_tpl->tpl_vars['person']->value) {
$_smarty_tpl->tpl_vars['person']->_loop = true;
$__foreach_person_1_saved_local_item = $_smarty_tpl->tpl_vars['person'];
?>
		<tr>
			<td><?php echo $_smarty_tpl->tpl_vars['person']->value['name'];?>
</td>
			<td><?php echo $_smarty_tpl->tpl_vars['person']->value['age'];?>
</td>
		</tr>
	<?php
$_smarty_tpl->tpl_vars['person'] = $__foreach_person_1_saved_local_item;
}
if (!$_smarty_tpl->tpl_vars['person']->_loop) {
?>
		无数据
	<?php
}
if ($__foreach_person_1_saved_item) {
$_smarty_tpl->tpl_vars['person'] = $__foreach_person_1_saved_item;
}
?>
</table>

<table border='1'>
	<?php
$_from = $_smarty_tpl->tpl_vars['bookList']->value;
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
		<tr>
			<td><?php echo $_smarty_tpl->tpl_vars['book']->value['name'];?>
</td>
			<td><?php echo ($_smarty_tpl->tpl_vars['book']->value['price']).("￥");?>
</td>
		</tr>
	<?php
$_smarty_tpl->tpl_vars['book'] = $__foreach_book_2_saved_local_item;
}
if ($__foreach_book_2_saved_item) {
$_smarty_tpl->tpl_vars['book'] = $__foreach_book_2_saved_item;
}
?>
</table>
<br />
<?php echo $_smarty_tpl->tpl_vars['obj']->value->fn(array('苹果','熟了'));?>

<br />
<?php echo date("Y-m-d",$_smarty_tpl->tpl_vars['time2']->value);?>

<br />
<?php echo $_smarty_tpl->tpl_vars['str']->value;?>

<br />
<?php echo str_replace('abc','aaa',$_smarty_tpl->tpl_vars['str']->value);?>






<?php }
}
