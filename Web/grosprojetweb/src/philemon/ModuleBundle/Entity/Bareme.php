<?php

namespace philemon\ModuleBundle\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * Bareme
 *
 * @ORM\Table(name="philemon_bareme")
 * @ORM\Entity(repositoryClass="philemon\ModuleBundle\Entity\BaremeRepository")
 */
class Bareme
{
	public function __toString()
	{
		return ($this->name);
	}
    /**
     * @var integer
     *
     * @ORM\Column(name="id", type="integer")
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="AUTO")
     */
    private $id;

    /**
     * @ORM\ManyToOne(targetEntity="Activity", inversedBy="baremes")
     * @ORM\JoinColumn(name="activity_id", referencedColumnName="id")
     */
     private $activity;

    /**
     * @var string
     *
     * @ORM\Column(name="name", type="string", length=255)
     */
    private $name;

    /**
     * @var string
     *
     * @ORM\Column(name="description", type="string", length=1024)
     */
    private $description;

	/**
     * @var integer
     *
     * @ORM\Column(name="displayo", type="integer")
     */
    private $displayo;

    /**
     * @var string
     *
     * @ORM\Column(name="checkbox", type="string", length=255)
     */
    private $checkbox;

    /**
     * Set displayo
     *
     * @param integer $displayo
     * @return BaremeCorrection
     */
    public function setDisplayo($displayo)
    {
        $this->displayo = $displayo;

        return $this;
    }

    /**
     * Get displayo
     *
     * @return integer 
     */
    public function getDisplayo()
    {
        return $this->displayo;
    }


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
     * Set name
     *
     * @param string $name
     * @return Bareme
     */
    public function setName($name)
    {
        $this->name = $name;

        return $this;
    }

    /**
     * Get name
     *
     * @return string 
     */
    public function getName()
    {
        return $this->name;
    }

    /**
     * Set description
     *
     * @param string $description
     * @return Bareme
     */
    public function setDescription($description)
    {
        $this->description = $description;

        return $this;
    }

    /**
     * Get description
     *
     * @return string 
     */
    public function getDescription()
    {
        return $this->description;
    }

    /**
     * Set checkbox
     *
     * @param string $checkbox
     * @return Bareme
     */
    public function setCheckbox($checkbox)
    {
        $this->checkbox = $checkbox;

        return $this;
    }

    /**
     * Get checkbox
     *
     * @return string 
     */
    public function getCheckbox()
    {
        return $this->checkbox;
    }

    /**
     * Set activity
     *
     * @param \philemon\ModuleBundle\Entity\Activity $activity
     * @return Bareme
     */
    public function setActivity(\philemon\ModuleBundle\Entity\Activity $activity = null)
    {
        $this->activity = $activity;

        return $this;
    }

    /**
     * Get activity
     *
     * @return \philemon\ModuleBundle\Entity\Activity 
     */
    public function getActivity()
    {
        return $this->activity;
    }
}
