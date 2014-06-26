<?php

namespace philemon\ModuleBundle\Entity;

use Doctrine\ORM\Mapping as ORM;

/**
 * ActivityLogin
 *
 * @ORM\Table(name="philemon_activity_login")
 * @ORM\Entity(repositoryClass="philemon\ModuleBundle\Entity\ActivityLoginRepository")
 */
class ActivityLogin
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
     * @ORM\ManyToOne(targetEntity="Activity")
     * @ORM\JoinColumn(name="activity_id", referencedColumnName="id")
     */
    private $activity;

    /**
     * @ORM\ManyToOne(targetEntity="\philemon\UserBundle\Entity\User")
     * @ORM\JoinColumn(name="user_id", referencedColumnName="id")
     */
    private $user;

    /**
     * @var float
     *
     * @ORM\Column(name="score", type="float")
     */
    private $score;


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
     * Set score
     *
     * @param float $score
     * @return ActivityLogin
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
     * @return ActivityLogin
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
     * @return ActivityLogin
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
