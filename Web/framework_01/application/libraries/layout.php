<?php if (!defined('BASEPATH')) exit('No direct script access allowed');

class Layout
{
	private $_CI;
	private $_var = array();
	private $_theme = 'default';

	public function __construct()
	{
		$this->_CI =& get_instance();
		$this->_CI->load->helper('assets');
		$this->_var['output'] = '';
		$this->_var['header'] = '';
		$this->_var['footer'] = '';
		$this->_var['nav'] = '';
		$this->_var['titre'] = ucfirst($this->_CI->router->fetch_method()) . ' - ' . ucfirst($this->_CI->router->fetch_class());
		$this->_var['charset'] = $this->_CI->config->item('charset');
		$this->_var['css'] = array();
		$this->_var['js'] = array();
	}

	public function set_default()
	{
		$this->add_css('style');
		$this->add_css('ui-shop');
		$this->add_css('icomoon/style');
		$this->set_header('elements/header');
		$this->set_footer('elements/footer');
		$this->set_nav('elements/nav');
	}

	public function views($name, $data = array())
	{
		$this->_var['output'] .= $this->_CI->load->view($name, $data, true);
		return $this;
	}

	public function set_titre($titre)
	{
		if(is_string($titre) AND !empty($titre))
		{
			$this->_var['titre'] = $titre;
			return true;
		}
		return false;
	}

	public function set_charset($charset)
	{
		if(is_string($charset) AND !empty($charset))
		{
			$this->_var['charset'] = $charset;
			return true;
		}
		return false;
	}

	public function set_theme($theme)
	{
		if(is_string($theme) AND !empty($theme) AND file_exists('./application/themes/' . $theme . '.php'))
		{
			$this->_theme = $theme;
			return true;
		}
		return false;
	}

	public function set_nav($name, $data = array())
	{
		$this->_var['nav'] = $this->_CI->load->view($name, $data, true);
		return $this;
	}

	public function set_footer($name, $data = array())
	{
		$this->_var['footer'] = $this->_CI->load->view($name, $data, true);
		return $this;
	}

	public function set_header($name, $data = array())
	{
		$this->_var['header'] = $this->_CI->load->view($name, $data, true);
		return $this;
	}

	public function view($name, $data = array())
	{
		$this->_var['output'] .= $this->_CI->load->view($name, $data, true);
		$this->_CI->load->view('../themes/' . $this->_theme, $this->_var);
	}

	public function add_css($nom)
	{
		if(is_string($nom) AND !empty($nom) AND file_exists('./assets/css/' . $nom . '.css'))
		{
			$this->_var['css'][] = css_url($nom);
			return true;
		}
		return false;
	}

	public function add_js($nom)
	{
		if(is_string($nom) AND !empty($nom) AND file_exists('./assets/javascript/' . $nom . '.js'))
		{
			$this->_var['js'][] = js_url($nom);
			return true;
		}
		return false;
	}
}

?>
