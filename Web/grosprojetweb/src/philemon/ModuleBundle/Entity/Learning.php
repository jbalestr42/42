<?php

namespace philemon\ModuleBundle\Entity;

use Doctrine\ORM\Mapping as ORM;
use Symfony\Component\Validator\Constraints as Assert;

/**
 * Learning
 *
 * @ORM\Table("philemon_learnings")
 * @ORM\Entity(repositoryClass="philemon\ModuleBundle\Entity\LearningRepository")
 */
class Learning
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
     * @ORM\ManyToOne(targetEntity="Activity", inversedBy="learnings")
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
     * @Assert\File(maxSize="5000k")
     */
    public $file;

    public function getWebPath()
    {
        return null === $this->name ? null : $this->getUploadDir().'/'.$this->name;
    }

    protected function getUploadRootDir()
    {
        // le chemin absolu du répertoire dans lequel sauvegarder les photos de profil
        return __DIR__.'/../../../../web/'.$this->getUploadDir();
    }

    protected function getUploadDir()
    {
        // get rid of the __DIR__ so it doesn't screw when displaying uploaded doc/image in the view.
        return 'uploads/pdf';
    }
    
    public function uploadProfilePicture()
    {
        // Nous utilisons le nom de fichier original, donc il est dans la pratique 
        // nécessaire de le nettoyer pour éviter les problèmes de sécurité

        // move copie le fichier présent chez le client dans le répertoire indiqué.
        $this->file->move($this->getUploadRootDir(), $this->file->getClientOriginalName());

        // On sauvegarde le nom de fichier
        $this->name = $this->file->getClientOriginalName();
        
        // La propriété file ne servira plus
        $this->file = null;
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
     * @return Learning
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
	 * Get activity
     *
     * @return \Doctrine\Common\Collections\Collection 
     */
    public function getActivity()
    {
        return $this->activity;
    }

	public function setActivity($activity)
	{
		$this->activity= $activity;
	}
}
