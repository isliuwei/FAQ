<?php if ( ! defined('BASEPATH')) exit('No direct script access allowed');

class Admin_model extends CI_Model {

    
    public function get_by_username_password($admin_username, $admin_password)
    {
        $data = array(
            'admin_username' => $admin_username,
            'admin_password' => $admin_password
        );
        $query = $this -> db -> get_where('t_admin',$data);

        return $query -> row();
    }


    public function get_all()
    {
    	return $this -> db -> get('t_admin') -> result();
    }


    public function save_admin_by_name_pwd_photo($name, $pwd,$photo_url)
    {
        $data = array(
            'admin_username' => $name,
            'admin_password' => $pwd,
            'admin_photo' => $photo_url
        );
        $this -> db -> insert('t_admin',$data);
        return $this -> db -> affected_rows();
    }

    public function get_by_username($admin_username)
    {
    	$data = array(
            'admin_username' => $admin_username
        );
        return $this -> db -> get_where('t_admin',$data) -> row();
    }

    public function get_admin_by_id($admin_id)
    {
    	$data = array(
    		'admin_id' => $admin_id
    	);
    	return $this -> db -> get_where('t_admin',$data) -> row();
    }

    public function updata_admin($admin_id,$admin_username,$admin_password,$url)
    {
    	$data = array(
            'admin_username' => $admin_username,
            'admin_password' => $admin_password,
            'admin_photo' => $url
        );

        $this -> db -> where('admin_id', $admin_id);
        $this -> db -> update('t_admin', $data);
        return $this -> db -> affected_rows();
    }

    public function save_contact_by_all($content,$name,$email)
    {
        $data = array(
            'contact_content' => $content,
            'contact_name' => $name,
            'contact_email' => $email
        );

        $this -> db -> insert('t_contact',$data);
        return $this -> db -> affected_rows();
    }


    public function get_all_contact()
    {
        return $this -> db -> get('t_contact') -> result();
    }

    public function delete_contact_by_id($id)
    {
        $this -> db -> delete('t_contact', array('contact_id' => $id));
        return $this -> db -> affected_rows();
    }


    public function get_all_partner()
    {
        return $this -> db -> get('t_partner') -> result();
    }
    public function get_partner_by_id($id)
    {
        return $this -> db -> get_where('t_partner',array('id' => $id)) -> row();
    }

    public function update_partner_info($id,$name,$web,$logo)
    {
        $data = array(
            'partner_name' => $name,
            'partner_web' => $web,
            'partner_img' => $logo
        );

        $this -> db -> where('id', $id);
        $this -> db -> update('t_partner', $data);
        return $this -> db -> affected_rows();
    }

    public function save_partner_by_all($name,$web,$url)
    {
        $data = array(
            'partner_name' => $name,
            'partner_web' => $web,
            'partner_img' => $url
        );

        $this -> db -> insert('t_partner',$data);
        return $this -> db -> affected_rows();
    }

    public function delete_partner_by_id($id)
    {
        $this -> db -> delete('t_partner', array('id' => $id));
        return $this -> db -> affected_rows();
    }

    public function get_all_case()
    {
        return $this -> db -> get('t_case') -> result();
    }

    public function save_case_by_all($main,$sub,$desc,$cate,$time,$content,$url)
    {
        $data = array(
            'case_mainTitle' => $main,
            'case_subTitle' => $sub,
            'case_desc' => $desc,
            'case_cate' => $cate,
            'case_time' => $time,
            'case_content' => $content,
            'case_img' => $url
        );

        $this -> db -> insert('t_case',$data);
        return $this -> db -> affected_rows();
    }

    public function delete_case_by_id($id)
    {
        $this -> db -> delete('t_case', array('case_id' => $id));
        return $this -> db -> affected_rows();
    }

    public function get_case_by_id($id)
    {
        return $this -> db -> get_where('t_case',array('case_id' => $id)) -> row();
    }

    public function update_case_by_all($id,$main,$sub,$cate,$desc,$time,$content,$url)
    {
        $data = array(
            'case_mainTitle' => $main,
            'case_subTitle' => $sub,
            'case_desc' => $desc,
            'case_cate' => $cate,
            'case_time' => $time,
            'case_content' => $content,
            'case_img' => $url
        );

        $this -> db -> where('case_id', $id);
        $this -> db -> update('t_case', $data);
        return $this -> db -> affected_rows();

    }


    public function get_carousel()
    {
        return $this -> db -> get('t_carousel') -> result();
    }


    


    

    

    

    




}