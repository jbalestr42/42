<?php

namespace philemon\ModuleBundle\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * ModuleLogin
 *
 * @ORM\Table(name="philemon_module_login")
 * @ORM\Entity(repositoryClass="philemon\ModuleBundle\Entity\ModuleLoginRepository")
 */
class ModuleLogin
{
    /**
     * @var integer
     *
     * @ORM\Column(name="id", type="integer")
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="AUTO")
     */
    private $id;

    /**
     * @ORM\ManyToOne(targetEntity="Module")
     * @ORM\JoinColumn(name="module_id", referencedColumnName="id")
     */
    private $module;

    /**
     * @ORM\ManyToOne(targetEntity="\philemon\UserBundle\Entity\User")
     * @ORM\JoinColumn(name="user_id", referencedColumnName="id")
     */
    private $user;

    /**
     * @var string
     *
     * @ORM\Column(name="grade", type="string", length=255)
     */
    private $grade;

    /**
     * @var integer
     *
     * @ORM\Column(name="average", type="integer")
     */
    private $average;


    /**
     * Get id
     *
     * @return integer 
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * Set grade
     *
     * @param string $grade
     * @return ModuleLogin
     */
    public function setGrade($grade)
    {
        $this->grade = $grade;

        return $this;
    }

    /**
     * Get grade
     *
     * @return string 
     */
    public function getGrade()
    {
        return $this->grade;
    }

    /**
     * Set average
     *
     * @param integer $average
     * @return ModuleLogin
     */
    public function setAverage($average)
    {
        $this->average = $average;

        return $this;
    }

    /**
     * Get average
     *
     * @return integer 
     */
    public function getAverage()
    {
        return $this->average;
    }

    /**
     * Set module
     *
     * @param \philemon\ModuleBundle\Entity\Module $module
     * @return ModuleLogin
     */
    public function setModule(\philemon\ModuleBundle\Entity\Module $module = null)
    {
        $this->module = $module;

        return $this;
    }

    /**
     * Get module
     *
     * @return \philemon\ModuleBundle\Entity\Module 
     */
    public function getModule()
    {
        return $this->module;
    }

    /**
     * Set user
     *
     * @param \philemon\UserBundle\Entity\User $user
     * @return ModuleLogin
     */
    public function setUser(\philemon\UserBundle\Entity\User $user = null)
    {
        $this->user = $user;

        return $this;
    }

    /**
     * Get user
     *
     * @return \philemon\UserBundle\Entity\User 
     */
    public function getUser()
    {
        return $this->user;
    }
}
