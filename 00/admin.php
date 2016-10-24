<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class Admin extends CI_Controller {

	function __construct() {
		parent::__construct();
		$this -> load-> library('email');
		$this -> load -> helper('captcha');
		$this -> load -> model('ader_model');
		$this -> load -> model('admin_model');
        $this -> load -> model('anchor_model');
        $this -> load -> model('company_model');

	}

	public function pre($data)
	{
		echo "<pre>";
		var_dump($data);
		echo "</pre>";
	}

	public function login()
	{
		$this -> load -> view('admin/login');
	}

	public function logout()
	{
		$this -> session -> unset_userdata('adminInfo');
      	redirect('admin/login');
	}

	public function index()
	{
        $aderCount = $this -> ader_model -> get_ader_count();
        $anchorCount = $this -> anchor_model -> get_anchor_count();
        $companyCount = $this -> company_model -> get_companyReg_count();
        $hit = read_file('hit.txt');

        $data = array(
            'aderCount' => $aderCount,
            'anchorCount' => $anchorCount,
            'companyCount' => $companyCount,
            'hit' => $hit
        );


		$this -> load -> view('admin/admin-index',$data);
	}

	public function check_login()
	{
        
        $admin_username = $this -> input -> post('admin_username');
        $admin_password = $this -> input -> post('admin_password');

        $row = $this -> admin_model -> get_by_username_password($admin_username, $admin_password);

        $data = array(
            'adminInfo' => $row
        );

        if($row)
        {
            $this -> session -> set_userdata($data);
            //$this -> load -> view('admin/admin-index');
            redirect('admin/index');
        }
        else
        {
            $this -> load -> view('admin/login');
        }

    }

    public function admin_mgr()
    {

        $result = $this -> admin_model -> get_all();
        if($result)
        {
            $data = array(
              'admins' => $result
            );
            $this -> load -> view('admin/admin-mgr',$data);
        }

    }

    public function add_admin()
    {
        $this -> load -> view('admin/admin-add');
    }

    public function save_admin()
    {
    	$admin_username = $this -> input -> post('admin_username');
    	$admin_password = $this -> input -> post('admin_password');


    	$config['upload_path'] = './uploads/';
        $config['allowed_types'] = 'gif|jpg|png';
        $config['max_size'] = '3072';
        $config['file_name'] = date("YmdHis") . '_' . rand(10000, 99999);

        //图片上传操作
        $this -> load -> library('upload', $config);
        $this -> upload -> do_upload('admin_photo');
        $upload_data = $this -> upload -> data();

        if ( $upload_data['file_size'] > 0 ) {
            //数据库中存photo的路径
            $photo_url = 'uploads/'.$upload_data['file_name'];
        }else{
            //如果不上传图片,则使用默认图片
            $photo_url = 'img/avatar.png';
        }

        $rows = $this -> admin_model -> save_admin_by_name_pwd_photo($admin_username,$admin_password, $photo_url);
        if($rows > 0)
        {
        	$data = array(
				'info'=>'注册成功',
				'url' => 'admin/admin_mgr'
			);
			$this -> load -> view('redirect-null',$data);
        }
        else
        {

        }


    }

    public function check_username()
    {
    	$admin_username = $this -> input -> get('admin_username');


        $result = $this -> admin_model -> get_by_username($admin_username);

        
        
        if($result)
        {
            echo 'success';
        }
        else
        {
            echo 'fail';
        }
    }

    public function admin_setting()
    {
    	$admin_id = $this -> input -> get('admin_id');
    	$row = $this -> admin_model -> get_admin_by_id($admin_id);

    	if($row)
    	{

    		$data = array(
    			'admin' => $row
    		);
    		$this -> load -> view('admin/admin-profile',$data);

    	}
    	
    }

    public function upload($filename,$default)
    {

    	$config['upload_path'] = './uploads/';
        $config['allowed_types'] = 'gif|jpg|png';
        $config['max_size'] = '3072';
        $config['file_name'] = date("YmdHis") . '_' . rand(10000, 99999);

        $this -> load -> library('upload', $config);
        $this -> upload -> do_upload($filename);
        $upload_data = $this -> upload -> data();

        if ( $upload_data['file_size'] > 0 ) 
        {
            $photo_url = 'uploads/'.$upload_data['file_name'];
        }
        else
        {
            $photo_url = $default;
        }

        return $photo_url;

    }

    public function updata_admin()
    {
    	$admin_id = $this -> input -> post('admin_id');
        $admin_username = $this -> input -> post('admin_username');
        $admin_password = $this -> input -> post('admin_password');
        $photo_old_url = $this -> input -> post('photo_old_url');
        $this -> upload('admin_photo',$photo_old_url);
        $url = $this -> upload('admin_photo',$photo_old_url);
       
        
        $row = $this -> admin_model -> updata_admin($admin_id,$admin_username,$admin_password,$url);

        if( $row == 0 )
        {
        	echo "<script>alert('未修改任何信息！')</script>";
			echo "<script>location.href='admin_setting?admin_id='+$admin_id;</script>";
        }
        else
        {
        	$data = array(
				'info'=>'信息更新成功！',
				'tip' => '请重新登录！',
				'page' => '登录页面',
				'url' => 'admin/login'
			);
			$this -> load -> view('redirect-null',$data);
        }
       
    }



    public function anchor_reg()
    {
    	$result = $this -> anchor_model -> get_all();

    	$data = array(
    		'anchors' => $result
    	);

    	$this -> load -> view('admin/anchor-list',$data);

    }


    public function enter_anchor_mgr()
    {
        $result = $this -> anchor_model -> get_by_enter();

        $data = array(
            'anchors' => $result
        );

        $this -> load -> view('admin/anchor-enter-list',$data);

    }

    public function anchor_delete()
    {
    	$anchor_id = $this -> input -> get('anchor_id');
    	$row = $this -> anchor_model -> delete_by_id($anchor_id);
    	if( $row > 0 )
    	{
    		echo "success";
    	}
    	else
    	{
    		echo "fail";
    	}
    }


    public function anchor_edit()
    {
    	$anchor_id = $this -> uri -> segment(3);
    	
    	$row = $this -> anchor_model -> get_anchor_by_id($anchor_id);

      	$anchorCates = $this -> anchor_model -> get_anchorCates_by_id($anchor_id);

      	$data =  array(
      		'anchor' => $row,
      		'anchorCates' => $anchorCates
      	);

    	$this -> load -> view('admin/anchor-edit',$data);


    	
    }


    public function update_anchor_info()
    {
        $id = $this -> input -> post('anchor_id',true);
        $name = $this -> input -> post('anchor_name',true);
        $sex = $this -> input -> post('anchor_gender',true);
        $username = $this -> input -> post('anchor_username',true);
        $password = $this -> input -> post('anchor_password',true);
        $platform = $this -> input -> post('anchor_platformName',true);
        $platformId = $this -> input ->post('anchor_platformID',true);
        $nickname = $this -> input ->post('anchor_platformNickname',true);
        $tel = $this -> input -> post('anchor_tel',true);
        $email = $this -> input -> post('anchor_email',true);
        $fansNumber = $this -> input -> post('anchor_fansNumber',true);
        $qq = $this -> input -> post('anchor_qqNum',true);
        $bank = $this -> input -> post('anchor_bankAccount',true);
        $attr = $this -> input -> post('anchor_attr',true);
        $region = $this -> input -> post('anchor_region',true);
        $province = $this -> input -> post('anchor_province',true);
        $cate = $this -> input -> post('cate',true);
        //$verify = $this -> input -> post('verify',true);
        $photo_old_url = $this -> input -> post('photo_old_url');
        $this -> upload('anchor_photo',$photo_old_url);
        $url = $this -> upload('anchor_photo',$photo_old_url);






        $info = array(
            'id' => $id,
            'name' => $name,
            'sex' => $sex,
            'username' => $username,
            'password' => $password,
            'platform' => $platform,
            'platformId' => $platformId,
            'nickname' => $nickname,
            'tel' => $tel,
            'email' => $email,
            'fansNumber' => $fansNumber,
            'qq' => $qq,
            'bank' => $bank,
            'attr' => $attr,
            'region' => $region,
            'province' => $province,
            'cate' => $cate,
            'url' => $url
        );

       

        $row = $this -> anchor_model -> update_anchor_info_by_admin($info);


        if( $row > 0 )
        {

            $data = array(
                'info'=>'信息更新成功！',
                'tip' => '请重新登录！',
                'page' => '登录页面',
                'url' => 'admin/anchor_reg'
            );
            $this -> load -> view('redirect-null',$data);
            
        }
        else
        {
            $data = array(
                'info'=>'信息未修改！',
                'page' => '信息编辑页面',
                'url' => 'admin/anchor_edit/'.$id
            );
            $this -> load -> view('redirect-null',$data);
        }

        
    }

    public function enter_anchor()
    {
        $this -> load -> view('admin/enter-anchor-sheet');
    }

    public function save_enter_anchor_info()
    {
        $isEnter = $this -> input -> post('isEnter',true);
        $name = $this -> input -> post('anchor_name',true);
        $sex = $this -> input -> post('anchor_gender',true);
        $username = $this -> input -> post('anchor_username',true);
        $password = $this -> input -> post('anchor_password',true);
        $platform = $this -> input -> post('anchor_platformName',true);
        $platformId = $this -> input ->post('anchor_platformID',true);
        $nickname = $this -> input ->post('anchor_platformNickname',true);
        $tel = $this -> input -> post('anchor_tel',true);
        $email = $this -> input -> post('anchor_email',true);
        $fansNumber = $this -> input -> post('anchor_fansNumber',true);
        $qq = $this -> input -> post('anchor_qqNum',true);
        $bank = $this -> input -> post('anchor_bankAccount',true);
        $attr = $this -> input -> post('anchor_attr',true);
        $region = $this -> input -> post('anchor_region',true);
        $province = $this -> input -> post('anchor_province',true);
        $cate = $this -> input -> post('cate',true);
        $this -> upload('anchor_photo',"");
        $url = $this -> upload('anchor_photo',"");


        $info = array(
            'isEnter' => $isEnter,
            'name' => $name,
            'sex' => $sex,
            'username' => $username,
            'password' => $password,
            'platform' => $platform,
            'platformId' => $platformId,
            'nickname' => $nickname,
            'tel' => $tel,
            'email' => $email,
            'fansNumber' => $fansNumber,
            'qq' => $qq,
            'bank' => $bank,
            'attr' => $attr,
            'region' => $region,
            'province' => $province,
            'cate' => $cate,
            'url' => $url
        );

        
        $row = $this -> anchor_model -> save_anchor_by_admin($info);

        if( $row > 0 )
        {
            $data = array(
                'info'=>'信息添加成功！',
                'page' => '列表页面',
                'url' => 'admin/enter_anchor_mgr'
            );
            $this -> load -> view('redirect-null',$data);
        }
        

    }

    public function ader_reg()
    {
        $result = $this -> ader_model -> get_all();

        $data = array(
            'aders' => $result
        );

        $this -> load -> view('admin/ader-list',$data);

    }


    public function ader_delete()
    {

        $ader_id = $this -> input -> get('ader_id');
        $row = $this -> ader_model -> delete_by_id($ader_id);
        if( $row > 0 )
        {
            echo "success";
        }
        else
        {
            echo "fail";
        }

    }


    public function ader_edit()
    {
        $ader_id = $this -> uri -> segment(3);
        
        $row = $this -> ader_model -> get_ader_by_id($ader_id);

        
        $data =  array(
            'ader' => $row
        );

        $this -> load -> view('admin/ader-edit',$data);
   
    }


    public function update_ader_info()
    {

        $id = $this -> input -> post('ader_id');
        $username = $this -> input -> post('ader_username');
        $password = $this -> input -> post('ader_password');
        $email = $this -> input -> post('ader_email');
        $tel = $this -> input -> post('ader_tel');
        $company = $this -> input -> post('ader_companyName');
        $website = $this -> input -> post('ader_website');

        $row = $this -> ader_model -> update_ader_by_all($id,$username,$password,$email,$tel,$company,$website);


        if( $row > 0 )
        {

            $data = array(
                'info'=>'信息更新成功！',
                'page' => '信息页面',
                'url' => 'admin/ader_reg'
            );
            $this -> load -> view('redirect-null',$data);
            
        }
        else
        {
            $data = array(
                'info'=>'信息未修改！',
                'page' => '信息编辑页面',
                'url' => 'admin/ader_edit/'.$id
            );
            $this -> load -> view('redirect-null',$data);
        }




    }

    public function enter_ader()
    {
        $this -> load -> view('admin/enter-ader-sheet');
    }


    public function save_enter_ader_info()
    {
       $isEnter = $this -> input -> post('isEnter');
       $username = $this -> input -> post('ader_username');
       $password = $this -> input -> post('ader_password');
       $email = $this -> input -> post('ader_email');
       $tel = $this -> input -> post('ader_tel');
       $company = $this -> input -> post('ader_companyName');
       $website = $this -> input -> post('ader_website');

       $row = $this -> ader_model -> save_ader_by_admin($isEnter,$username,$password,$email,$tel,$company,$website);
       if( $row > 0)
       {
            $data = array(
                'info'=>'信息添加成功！',
                'page' => '列表页面',
                'url' => 'admin/enter_ader_mgr'
            );
            $this -> load -> view('redirect-null',$data);
       }

    }



    public function enter_ader_mgr()
    {

        $result = $this -> ader_model -> get_by_enter();

        $data = array(
            'aders' => $result
        );

        $this -> load -> view('admin/ader-enter-list',$data);

    }

    public function anchor_need()
    {
        $result = $this -> anchor_model -> get_all_anchor_need();
        $data = array(
            'anchorNeeds' => $result
        );
        $this -> load -> view('admin/anchor-need-list',$data);
    }

    public function anchorNeed_delete()
    {
        $anchorNeed_id = $this -> input -> get('anchorNeed_id');
        $row = $this -> anchor_model -> delete_need_by_id($anchorNeed_id);
        if( $row > 0 )
        {
            echo "success";
        }
        else
        {
            echo "fail";
        }
    }

    public function anchorNeed_edit()
    {
        $anchorNeed_id = $this -> uri -> segment(3);
        $row = $this -> anchor_model -> get_need_by_id($anchorNeed_id);


        
        $data = array(
            'anchorNeed' => $row
        );
        $this -> load -> view('admin/anchorNeed-edit',$data);
       
    }


    public function update_anchorNeed_info()
    {
        $id = $this -> input -> post('anchorNeed_id');
        $brand = $this -> input -> post('anchorNeed_brand');
        $pro = $this -> input -> post('anchorNeed_pro');
        $time = $this -> input -> post('anchorNeed_time');
        $cycle = $this -> input -> post('anchorNeed_cycle');
        $number = $this -> input -> post('anchorNeed_number');
        $fansNumber = $this -> input -> post('anchorNeed_fansNumber');
        $coop = $this -> input -> post('anchorNeed_coopCate');
        $other = $this -> input -> post('anchorNeed_otherNeed');

        $photo_old_url = $this -> input -> post('photo_old_url');
        $this -> upload('anchorNeed_logo',$photo_old_url);
        $logo = $this -> upload('anchorNeed_logo',$photo_old_url);


        $row = $this -> anchor_model -> update_anchorNeed_by_admin($id,$brand,$pro,$time,$cycle,$number,$fansNumber,$coop,$other,$logo);

        if( $row > 0 )
        {
            $data = array(
                'info'=>'信息更新成功！',
                'page' => '信息页面',
                'url' => 'admin/anchor_need'
            );
            $this -> load -> view('redirect-null',$data);
        }
        else
        {
            $data = array(
                'info'=>'信息未修改！',
                'page' => '信息编辑页面',
                'url' => 'admin/anchorNeed_edit/'.$id
            );
            $this -> load -> view('redirect-null',$data);
        }

    }

    public function company_need()
    {

        $result = $this -> company_model -> get_all_company_need();
        $data = array(
            'companyNeeds' => $result
        );
        $this -> load -> view('admin/company-need-list',$data);

    }

    public function companyNeed_delete()
    {
        $companyNeed_id = $this -> input -> get('companyNeed_id');
        $row = $this -> company_model -> delete_need_by_id($companyNeed_id);
        if( $row > 0 )
        {
            echo "success";
        }
        else
        {
            echo "fail";
        }

    }

    public function companyNeed_edit()
    {
        $companyNeed_id = $this -> uri -> segment(3);

        $row = $this -> company_model -> get_need_by_id($companyNeed_id);
        
        $data = array(
            'companyNeed' => $row
        );
        $this -> load -> view('admin/companyNeed-edit',$data);
    }


    public function update_companyNeed_info()
    {
        $id = $this -> input -> post('companyNeed_id',true);
        $brand = $this -> input -> post('companyNeed_brand',true);
        $pro = $this -> input -> post('companyNeed_pro',true);
        $time = $this -> input -> post('companyNeed_time',true);
        $cycle = $this -> input -> post('companyNeed_cycle',true);
        $bud = $this -> input -> post('companyNeed_bud',true);
        $other = $this -> input -> post('companyNeed_others',true);

        $photo_old_url = $this -> input -> post('photo_old_url');
        $this -> upload('companyNeed_photo',$photo_old_url);
        $logo = $this -> upload('companyNeed_photo',$photo_old_url);


        $row = $this -> company_model -> update_companyNeed_by_admin($id,$brand,$pro,$time,$cycle,$bud,$other,$logo);

        if( $row > 0 )
        {
            $data = array(
                'info'=>'信息更新成功！',
                'page' => '信息页面',
                'url' => 'admin/company_need'
            );
            $this -> load -> view('redirect-null',$data);
        }
        else
        {
            $data = array(
                'info'=>'信息未修改！',
                'page' => '信息编辑页面',
                'url' => 'admin/companyNeed_edit/'.$id
            );
            $this -> load -> view('redirect-null',$data);
        }


    }

    public function material_mgr()
    {
        $result = $this -> anchor_model -> get_all_material();

        $data = array(
            'matertial' => $result
        );
        
        $this -> load -> view('admin/material-list',$data);
    }

    public function material_edit()
    {
        $id = $this -> uri ->segment(3);
        $row = $this -> anchor_model -> get_material_by_id($id);

        if( $row )
        {
            $data = array(
                'material' => $row
            );

            $this -> load -> view('admin/material-edit',$data);
        }

    }

    public function updata_material()
    {
        $id = $this -> input -> post('id',true);
        $name = $this -> input -> post('material_name',true);
        $website = $this -> input -> post('material_website',true);

        $photo_old_url = $this -> input -> post('photo_old_url');
        $this -> upload('material_img',$photo_old_url);
        $logo = $this -> upload('material_img',$photo_old_url);

        $row = $this -> anchor_model -> update_materail_info($id,$name,$website,$logo);

        if( $row > 0)
        {
            $data = array(
                'info'=>'信息更新成功！',
                'page' => '信息页面',
                'url' => 'admin/material_mgr'
            );
            $this -> load -> view('redirect-null',$data);
        }
        else
        {
            $data = array(
                'info'=>'信息未修改！',
                'page' => '信息编辑页面',
                'url' => 'admin/material_edit/'.$id
            );
            $this -> load -> view('redirect-null',$data);
        }
    }


    public function company_reg()
    {
        $result = $this -> company_model -> get_all();

        $data = array(
            'companys' => $result
        );


        $this -> load -> view('admin/company-list',$data);

    }

    public function company_delete()
    {
        $company_id = $this -> input -> get('company_id');
        $row = $this -> company_model -> delete_by_id($company_id);
        if( $row > 0 )
        {
            echo "success";
        }
        else
        {
            echo "fail";
        }
    }

    public function enter_company()
    {
        $this -> load -> view('admin/enter-company-sheet');
    }

    public function save_enter_company_info()
    {
        $isEnter = $this -> input -> post('isEnter',true);
        $username = $this -> input -> post('company_username',true);
        $email = $this -> input -> post('company_email',true);
        $password = $this -> input -> post('company_password',true);
        $tel = $this -> input -> post('company_tel',true);
        $name = $this -> input -> post('company_name',true);
        $web = $this -> input -> post('company_website',true);
        $resourceCate = $this -> input -> post('resourceCate',true);
        $resourceCity = $this -> input -> post('resourceCity',true);

        function createStr($array,$attr)
        {
            $string = "";
            for($i=0;$i<count($array);$i++){
                $string.=$array[$i]->$attr.',';
            };
            return substr($string,0,-1);

        }

        if($resourceCate)
        {
            $catesql = implode(',',$resourceCate); 
            $cates = $this -> company_model -> getCates($catesql);
            $catesString = createStr($cates,'aderResourceName');
        }
        else
        {
            $catesString="";
        }

        if($resourceCity)
        {
            $citysql = implode(',',$resourceCity);
            $citys = $this -> company_model -> getCitys($citysql);
            $citysString = createStr($citys,'aderCity_name');
        }
        else
        {
            $citysString="";
        }
        
        $row = $this -> company_model -> save_by_admin($isEnter,$username,$email,$password,$tel,$name,$web,$catesString,$citysString,$resourceCate,$resourceCity);


        if($row>0)
        {
            $data = array(
                'info'=>'信息添加成功！',
                'page' => '列表页面',
                'url' => 'admin/enter_company_mgr'
            );
            $this -> load -> view('redirect-null',$data);

            
        }
          

    }


    public function enter_company_mgr()
    {

        $result = $this -> company_model -> get_by_enter();

        $data = array(
            'companys' => $result
        );

        $this -> load -> view('admin/company-enter-list',$data);

    }

    public function company_edit()
    {
        $id = $this -> uri -> segment(3);
        $companyInfo = $this -> company_model -> get_by_id($id);

        function createStr($array,$attr)
        {
            $string = "";
            for($i=0;$i<count($array);$i++){
                $string.=$array[$i]->$attr.',';
            };
            return substr($string,0,-1);

        }
        $resourceCate = $this -> company_model -> get_resourceCate_by_id($id);
        $resourceCity = $this -> company_model -> get_resourceCity_by_id($id);
        if($resourceCate)
        {
            
            $str1 = createStr($resourceCate,'companyResourceCate_id');

            $resourceCateString = $this -> ader_model -> get_resource_cate($str1);
        }
        else
        {
            $resourceCateString = "";
        }


        if($resourceCity)
        {
            
            $str2 = createStr($resourceCity,'companyCity_id');

            $resourceCityString = $this -> ader_model -> get_ader_city($str2);
        }

        else
        {
            $resourceCityString = "";
        }

        
        $data = array(
            'company' => $companyInfo,
            'cates' => $resourceCateString,
            'citys' => $resourceCityString
        );
        // var_dump($data);
        // die();

        $this -> load -> view('admin/company-edit',$data);


    }

    public function update_company_info()
    {
        $id = $this -> input -> post('company_id',true);
        $username = $this -> input -> post('company_username',true);
        $email = $this -> input -> post('company_email',true);
        $password = $this -> input -> post('company_password',true);
        $tel = $this -> input -> post('company_tel',true);
        $name = $this -> input -> post('company_name',true);
        $web = $this -> input -> post('company_website',true);

        $resourceCate = $this -> input -> post('resourceCate',true);
        $resourceCity = $this -> input -> post('resourceCity',true);

        // var_dump($resourceCate);
        // die();

        function createStr($array,$attr)
        {
            $string = "";
            for($i=0;$i<count($array);$i++){
                $string.=$array[$i]->$attr.',';
            };
            return substr($string,0,-1);

        }

        if($resourceCate)
        {
            $catesql = implode(',',$resourceCate); 
            $cates = $this -> company_model -> getCates($catesql);
            $catesString = createStr($cates,'aderResourceName');
        }
        else
        {
            $catesString="";
        }

        if($resourceCity)
        {
            $citysql = implode(',',$resourceCity);
            $citys = $this -> company_model -> getCitys($citysql);
            $citysString = createStr($citys,'aderCity_name');
        }
        else
        {
            $citysString="";
        }

        $row = $this -> company_model -> update_by_admin($id,$username,$email,$password,$tel,$name,$web,$catesString,$citysString,$resourceCate,$resourceCity);

        if( $row > 0 )
        {

            $data = array(
                'info'=>'信息更新成功！',
                'page' => '信息页面',
                'url' => 'admin/company_reg'
            );
            $this -> load -> view('redirect-null',$data);
            
        }
        else
        {
            $data = array(
                'info'=>'信息未修改！',
                'page' => '信息编辑页面',
                'url' => 'admin/company_edit/'.$id
            );
            $this -> load -> view('redirect-null',$data);
        }
        
        
    }

    public function cooperate_mgr()
    {
        $id = $this -> uri -> segment(3);

        $result = $this -> company_model -> get_cooperate_by_id($id);

        $data = array(
            'cooperateInfo' => $result
        );
        $this -> load -> view('admin/cooperate-list',$data);
    }

    public function add_cooperate()
    {
        $this -> load -> view('admin/add-cooperate');
    }

    public function save_cooperate()
    {
        $id = $this -> input -> post('cooperate_id',true);
        $company = $this -> input -> post('cooperate_company',true);
        $resource = $this -> input -> post('cooperate_resource',true);
        $region = $this -> input -> post('cooperate_region',true);
        $bud = $this -> input -> post('cooperate_bud',true);
        $time = $this -> input -> post('cooperate_time',true);

        $row = $this -> company_model -> save_cooperate_by_company_id($id,$company,$resource,$region,$bud,$time);

        if( $row > 0 )
        {

            $data = array(
                'info'=>'添加成功！',
                'page' => '列表页面',
                'url' => 'admin/cooperate_mgr/'.$id
            );
            $this -> load -> view('redirect-null',$data);
            
        }
        
    }

    public function cooperate_edit()
    {
        $coop_id = $this -> uri -> segment(3);
        $row = $this -> company_model -> get_cooperate_by_coop_id($coop_id);

        $data = array(
            'cooperate' => $row
        );



        $this -> load -> view('admin/cooperate-edit',$data);

    }

    public function update_cooperate()
    {
        $id = $this -> input -> post('cooperate_id',true);
        $company = $this -> input -> post('cooperate_company',true);
        $resource = $this -> input -> post('cooperate_resource',true);
        $region = $this -> input -> post('cooperate_region',true);
        $bud = $this -> input -> post('cooperate_bud',true);
        $time = $this -> input -> post('cooperate_time',true);

        $row = $this -> company_model -> update_coop_by_coop_id($id,$company,$resource,$region,$bud,$time);

        if( $row > 0 )
        {

            $data = array(
                'info'=>'信息更新成功！',
                'page' => '信息页面',
                'url' => 'admin/company_reg'
            );
            $this -> load -> view('redirect-null',$data);
            
        }
        else
        {
            $data = array(
                'info'=>'信息未修改！',
                'page' => '信息编辑页面',
                'url' => 'admin/cooperate_edit/'.$id
            );
            $this -> load -> view('redirect-null',$data);
        }


    }


    public function cooperate_delete()
    {

        $cooperate_id = $this -> input -> get('cooperate_id');
        $row = $this -> company_model -> delete_coop_by_id($cooperate_id);
        if( $row > 0 )
        {
            echo "success";
        }
        else
        {
            echo "fail";
        }

    }

    public function save_contact()
    {
        $content = $this -> input -> post('content');
        $name = $this -> input -> post('name');
        $email = $this -> input -> post('email');
        
        $row = $this -> admin_model -> save_contact_by_all($content,$name,$email);

        if( $row > 0)
        {

            $data = array(
                'info'=>'留言成功！',
                'page' => '首页',
                'url' => 'welcome/index'
            );
            $this -> load -> view('redirect-null',$data);

        }


    }

    public function contact_mgr()
    {
        $result = $this -> admin_model -> get_all_contact();
        $data = array(
            'contacts' => $result
        );
        $this -> load -> view('admin/contact-list',$data);
    }

    


    public function contact_delete()
    {
        $id = $this -> input -> get('contact_id');
        $row = $this -> admin_model -> delete_contact_by_id($id);
        if( $row > 0 )
        {
            echo "success";
        }
        else
        {
            echo "fail";
        }
    }


    public function partner_mgr()
    {
        $result = $this -> admin_model -> get_all_partner();

        $data = array(
            'partners' => $result
        );

        $this -> load -> view('admin/partner-list',$data);
    }


    public function partner_edit()
    {
        $id = $this -> uri -> segment(3);
        $row = $this -> admin_model -> get_partner_by_id($id);

        if( $row )
        {
            $data = array(
                'partner' => $row
            );

            $this -> load -> view('admin/partner-edit',$data);
        }
    }


    public function updata_partner()
    {

        $id = $this -> input -> post('id',true);
        $name = $this -> input -> post('partner_name',true);
        $web = $this -> input -> post('partner_web',true);

        $photo_old_url = $this -> input -> post('photo_old_url');
        $this -> upload('partner_img',$photo_old_url);
        $logo = $this -> upload('partner_img',$photo_old_url);

        $row = $this -> admin_model -> update_partner_info($id,$name,$web,$logo);

        if( $row > 0)
        {
            $data = array(
                'info'=>'信息更新成功！',
                'page' => '信息页面',
                'url' => 'admin/partner_mgr'
            );
            $this -> load -> view('redirect-null',$data);
        }
        else
        {
            $data = array(
                'info'=>'信息未修改！',
                'page' => '信息编辑页面',
                'url' => 'admin/partner_edit/'.$id
            );
            $this -> load -> view('redirect-null',$data);
        }

    }


    public function add_partner()
    {
        $this -> load -> view('admin/partner-add');
    }


    public function save_partner()
    {
        $name = $this -> input -> post('partner_name');
        $web = $this -> input -> post('partner_web');
        $this -> upload('partner_img',"");
        $url = $this -> upload('partner_img',"");

        $row = $this -> admin_model -> save_partner_by_all($name,$web,$url);

        if( $row > 0 )
        {

            $data = array(
                'info'=>'添加成功！',
                'page' => '列表页面',
                'url' => 'admin/partner_mgr'
            );
            $this -> load -> view('redirect-null',$data);
            
        }
    }

    public function partner_delete()
    {
        $id = $this -> input -> get('partner_id');
        $row = $this -> admin_model -> delete_partner_by_id($id);
        if( $row > 0 )
        {
            echo "success";
        }
        else
        {
            echo "fail";
        }

    }


    public function case_mgr()
    {
        $result = $this -> admin_model -> get_all_case();

        $data = array(
            'cases' => $result
        );

        $this -> load -> view('admin/case-list',$data);
        
    }

    public function add_case()
    {
        $this -> load -> view('admin/case_add');
    }


    public function save_case()
    {
        $main = $this -> input -> post('case_mainTitle');
        $sub = $this -> input -> post('case_subTitle');
        $desc = $this -> input -> post('case_desc');
        $cate = $this -> input -> post('case_cate');
        $time = $this -> input -> post('case_time');
        $content = $this -> input -> post('case_content');




        $this -> upload('case_img',"");
        $url = $this -> upload('case_img',"");
        $row = $this -> admin_model -> save_case_by_all($main,$sub,$desc,$cate,$time,$content,$url);



        if( $row > 0 )
        {

            $data = array(
                'info'=>'添加成功！',
                'page' => '列表页面',
                'url' => 'admin/case_mgr'
            );
            $this -> load -> view('redirect-null',$data);
            
        }

    }


    public function case_delete()
    {
        $id = $this -> input -> get('case_id');
        $row = $this -> admin_model -> delete_case_by_id($id);
        if( $row > 0 )
        {
            echo "success";
        }
        else
        {
            echo "fail";
        }

    }

    public function case_edit()
    {

        $id = $this -> uri -> segment(3);
        $row = $this -> admin_model -> get_case_by_id($id);

        if( $row )
        {
            $data = array(
                'case' => $row
            );

            $this -> load -> view('admin/case-edit',$data);
        }

    }

    public function update_case()
    {
        $id = $this -> input -> post('case_id');
        $main = $this -> input -> post('case_mainTitle');
        $sub = $this -> input -> post('case_subTitle');
        $cate = $this -> input -> post('case_cate');
        $desc = $this -> input -> post('case_desc');
        $time = $this -> input -> post('case_time');
        $content = $this -> input -> post('case_content'); 
        $photo_old_url = $this -> input -> post('photo_old_url');


        $config['upload_path'] = './uploads/';
        $config['allowed_types'] = 'gif|jpg|png';
        $config['max_size'] = '3072';
        $config['file_name'] = date("YmdHis") . '_' . rand(10000, 99999);

        //图片上传操作
        $this -> load -> library('upload', $config);
        $this -> upload -> do_upload('case_img');
        $upload_data = $this -> upload -> data();

        if ( $upload_data['file_size'] > 0 ) {
            //数据库中存photo的路径
            $url = 'uploads/'.$upload_data['file_name'];
        }else{
            //如果不上传图片,则使用原来图片
            $url = $photo_old_url;
        }


        $row = $this -> admin_model -> update_case_by_all($id,$main,$sub,$cate,$desc,$time,$content,$url);


        if( $row > 0)
        {
            $data = array(
                'info'=>'信息更新成功！',
                'page' => '信息页面',
                'url' => 'admin/case_mgr'
            );
            $this -> load -> view('redirect-null',$data);
        }
        else
        {
            $data = array(
                'info'=>'信息未修改！',
                'page' => '信息编辑页面',
                'url' => 'admin/case_edit/'.$id
            );
            $this -> load -> view('redirect-null',$data);
        }



    }


    public function carousel_mgr()
    {
        $result = $this -> admin_model -> get_carousel();

        var_dump($result);
        die();

        $this -> load -> view('admin/carousel-list');
    }















	



}