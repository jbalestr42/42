<?php

namespace philemon\UserBundle\Entity;

use FOS\UserBundle\Model\User as BaseUser;
use FR3D\LdapBundle\Model\LdapUserInterface;
use Doctrine\ORM\Mapping as ORM;

/**
 * @ORM\Entity
 * @ORM\Table(name="philemon_user")
 */
class User extends BaseUser implements LdapUserInterface
{
     /**
     * @ORM\Id
     * @ORM\Column(type="integer")
     * @ORM\GeneratedValue(strategy="AUTO")
     */
     protected $id;

     /**
     * Ldap Object Distinguished Name
     * @ORM\Column(type="string", length=128)
     * @var string $dn
     */
     private $dn;

    /**
     * {@inheritDoc}
     */
    public function setDn($dn)
    {
        $this->dn = $dn;
    }

    /**
     * {@inheritDoc}
     */
    public function getDn()
    {
        return $this->dn;
    }

	/**
     * @ORM\Column(type="string", length=128)
     * @var string $name
     */
	protected $name;

	/**
     * {@inheritDoc}
     */
	public function setName($name)
	{
		$this->name = $name;
	}
	/**
     * {@inheritDoc}
     */
	public function getName()
	{
		return $this->name;
	}

	/**
     * @ORM\Column(type="string", length=128)
     * @var string $Nbuid
     */
	protected $Nbuid;

	/**
     * {@inheritDoc}
     */
	public function setNbuid($Nbuid)
	{
		$this->Nbuid = $Nbuid;
	}
	/**
     * {@inheritDoc}
     */
	public function getNbuid()
	{
		return $this->Nbuid;
	}

}
