<?php

namespace philemon\ModuleBundle\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * Correction
 *
 * @ORM\Table(name="philemon_correction")
 * @ORM\Entity(repositoryClass="philemon\ModuleBundle\Entity\CorrectionRepository")
 */
class Correction
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
     * @ORM\ManyToOne(targetEntity="Activity", inversedBy="corrections")
     * @ORM\JoinColumn(name="activity_id", referencedColumnName="id")
     */
    private $activity;

    /**
     * @ORM\ManyToOne(targetEntity="\philemon\UserBundle\Entity\User")
     * @ORM\JoinColumn(name="user_id", referencedColumnName="id")
     */
    private $user;

    /**
     * @ORM\ManyToOne(targetEntity="\philemon\UserBundle\Entity\User")
     * @ORM\JoinColumn(name="corrector_id", referencedColumnName="id")
     */
    private $corrector;

    /**
     * @var float
     *
     * @ORM\Column(name="score", type="float", nullable=true)
     */
    private $score = null;

	/**
     * @var string
     *
     * @ORM\Column(name="comment", type="string", length=4096)
     */
    private $comment;

	/**
     * @var string
     *
     * @ORM\Column(name="ratetext", type="string", length=1024)
     */
    private $ratetext;

	/**
     * @var integer
     *
     * @ORM\Column(name="rate", type="integer", nullable=true)
     */
    private $rate = null;

	/**
     * @var string
     *
     * @ORM\Column(name="ratescore", type="string")
     */
    private $ratescore;

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
     * Set ratescore
     *
     * @param string $ratescore
     * @return Correction
     */
    public function setRatescore($ratescore)
    {
        $this->ratescore = $ratescore;

        return $this;
    }

    /**
     * Get ratescore
     *
     * @return string $ratescore
     */
    public function getRatescore()
    {
        return $this->ratescore;
    }


    /**
     * Set rate
     *
     * @param integer $rate
     * @return Correction
     */
    public function setRate($rate)
    {
        $this->rate = $rate;

        return $this;
    }

    /**
     * Get rate
     *
     * @return integer
     */
    public function getRate()
    {
        return $this->rate;
    }

    /**
     * Set score
     *
     * @param float $score
     * @return Correction
     */
    public function setScore($score)
    {
        $this->score = $score;

        return $this;
    }

    /**
     * Get score
     *
     * @return float 
     */
    public function getScore()
    {
        return $this->score;
    }

    /**
     * Set activity
     *
     * @param \philemon\ModuleBundle\Entity\Activity $activity
     * @return Correction
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

    /**
     * Set user
     *
     * @param \philemon\UserBundle\Entity\User $user
     * @return Correction
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

    /**
     * Set corrector
     *
     * @param \philemon\UserBundle\Entity\User $corrector
     * @return Correction
     */
    public function setCorrector(\philemon\UserBundle\Entity\User $corrector = null)
    {
        $this->corrector = $corrector;

        return $this;
    }

    /**
     * Get corrector
     *
     * @return \philemon\UserBundle\Entity\User 
     */
    public function getCorrector()
    {
        return $this->corrector;
    }

	/**
     * Set comment
     *
     * @param string $comment
     * @return Correction
     */
    public function setComment($comment)
    {
        $this->comment = $comment;

        return $this;
    }

    /**
     * Get comment
     *
     * @return string 
     */
    public function getComment()
    {
        return $this->comment;
    }

	/**
     * Set ratetext
     *
     * @param string $ratetext
     * @return Correction
     */
    public function setRatetext($ratetext)
    {
        $this->ratetext = $ratetext;

        return $this;
    }

    /**
     * Get ratetext
     *
     * @return string 
     */
    public function getRatetext()
    {
        return $this->ratetext;
    }
}
