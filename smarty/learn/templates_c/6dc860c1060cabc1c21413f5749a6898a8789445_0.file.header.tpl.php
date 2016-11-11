<?php
/* Smarty version 3.1.29, created on 2016-11-09 18:09:30
  from "/Applications/XAMPP/xamppfiles/htdocs/smarty/learn/templates/header.tpl" */

if ($_smarty_tpl->smarty->ext->_validateCompiled->decodeProperties($_smarty_tpl, array (
  'has_nocache_code' => false,
  'version' => '3.1.29',
  'unifunc' => 'content_5823584a1910e6_65785592',
  'file_dependency' => 
  array (
    '6dc860c1060cabc1c21413f5749a6898a8789445' => 
    array (
      0 => '/Applications/XAMPP/xamppfiles/htdocs/smarty/learn/templates/header.tpl',
      1 => 1478711358,
      2 => 'file',
    ),
  ),
  'includes' => 
  array (
  ),
),false)) {
function content_5823584a1910e6_65785592 ($_smarty_tpl) {
?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Smarty</title>
	<style>
		header{
			background: #aaa;
			width: 100%;
			height: 200px;
			line-height: 200px;
			border-radius: 20px;
		}

		header h1{
			text-align: center;
			color: #fff;

		}
		
	</style>
</head>
<body>
<header>
	<h1>Smarty 模板引擎的基本使用 <small><?php echo $_smarty_tpl->tpl_vars['filename']->value;?>
</small></h1>
</header>

	
<?php }
}
