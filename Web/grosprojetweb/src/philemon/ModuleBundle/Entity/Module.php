<?php

namespace philemon\ModuleBundle\Entity;

use Doctrine\ORM\Mapping as ORM;
use Doctrine\Common\Collections\ArrayCollection;

/**
 * Module
 *
 * @ORM\Table(name="philemon_module")
 * @ORM\Entity(repositoryClass="philemon\ModuleBundle\Entity\ModuleRepository")
 */
class Module
{
	public function __construct()
	{
		$tmp = new \Datetime('NOW');
		$this->dateStartInscription = $tmp;
		$this->dateEndInscription = $tmp;
		$this->dateStart = $tmp;
		$this->dateEnd = $tmp;
		$this->activities = new ArrayCollection();
	}

	public function __toString()
	{
		return $this->name;
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
    * @ORM\OneToMany(targetEntity="Activity", mappedBy="module", cascade={"persist", "remove"}, orphanRemoval=true)
    */
    private $activities;

    /**
     * @var string
     *
     * @ORM\Column(name="name", type="string", length=255)
     */
    private $name;

    /**
     * @var string
     *
     * @ORM\Column(name="description", type="string", length=255)
     */
    private $description;

    /**
     * @var integer
     *
     * @ORM\Column(name="max_place", type="integer")
     */
    private $maxPlace;

    /**
     * @var \DateTime
     *
     * @ORM\Column(name="date_start_inscription", type="datetime")
     */
    private $dateStartInscription;

    /**
     * @var \DateTime
     *
     * @ORM\Column(name="date_end_inscription", type="datetime")
     */
    private $dateEndInscription;

    /**
     * @var \DateTime
     *
     * @ORM\Column(name="date_start", type="datetime")
     */
    private $dateStart;

    /**
     * @var \DateTime
     *
     * @ORM\Column(name="date_end", type="datetime")
     */
    private $dateEnd;

    /**
     * @var integer
     *
     * @ORM\Column(name="credit", type="integer")
     */
    private $credit;

	public function setActivities($activities)
	{
        if (gettype($activities) == "array") {
            $activities= new ArrayCollection($activities);
        }

        foreach($activities as $a)
        {
            $a->setModule($this);
        }
        $this->activities = $activities;
	}

	public function addActivities(\philemon\ModuleBundle\Entity\Activity $activity)
	{
		$activity->setModule($this);
		$this->activities->add($activity);
		return ($this);
	}

	public function removeActivities(\philemon\ModuleBundle\Entity\Activity $activity)
	{
		$this->activities->removeElement($activity);
	}

	public function getActivities()
	{
		return $this->activities;
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
     * @return Module
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
     * @return Module
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
     * Set maxPlace
     *
     * @param integer $maxPlace
     * @return Module
     */
    public function setMaxPlace($maxPlace)
    {
        $this->maxPlace = $maxPlace;

        return $this;
    }

    /**
     * Get maxPlace
     *
     * @return integer 
     */
    public function getMaxPlace()
    {
        return $this->maxPlace;
    }

    /**
     * Set dateStartInscription
     *
     * @param \DateTime $dateStartInscription
     * @return Module
     */
    public function setDateStartInscription($dateStartInscription)
    {
        $this->dateStartInscription = $dateStartInscription;

        return $this;
    }

    /**
     * Get dateStartInscription
     *
     * @return \DateTime 
     */
    public function getDateStartInscription()
    {
        return $this->dateStartInscription;
    }

    /**
     * Set dateEndInscription
     *
     * @param \DateTime $dateEndInscription
     * @return Module
     */
    public function setDateEndInscription($dateEndInscription)
    {
        $this->dateEndInscription = $dateEndInscription;

        return $this;
    }

    /**
     * Get dateEndInscription
     *
     * @return \DateTime 
     */
    public function getDateEndInscription()
    {
        return $this->dateEndInscription;
    }

    /**
     * Set dateStart
     *
     * @param \DateTime $dateStart
     * @return Module
     */
    public function setDateStart($dateStart)
    {
        $this->dateStart = $dateStart;

        return $this;
    }

    /**
     * Get dateStart
     *
     * @return \DateTime 
     */
    public function getDateStart()
    {
        return $this->dateStart;
    }

    /**
     * Set dateEnd
     *
     * @param \DateTime $dateEnd
     * @return Module
     */
    public function setDateEnd($dateEnd)
    {
        $this->dateEnd = $dateEnd;

        return $this;
    }

    /**
     * Get dateEnd
     *
     * @return \DateTime 
     */
    public function getDateEnd()
    {
        return $this->dateEnd;
    }

    /**
     * Set credit
     *
     * @param integer $credit
     * @return Module
     */
    public function setCredit($credit)
    {
        $this->credit = $credit;

        return $this;
    }

    /**
     * Get credit
     *
     * @return integer 
     */
    public function getCredit()
    {
        return $this->credit;
    }
}
