<?php

namespace philemon\ModuleBundle\Admin;

use Sonata\AdminBundle\Admin\Admin;
use Sonata\AdminBundle\Datagrid\ListMapper;
use Sonata\AdminBundle\Datagrid\DatagridMapper;
use Sonata\AdminBundle\Form\FormMapper;

class ModuleAdmin extends Admin
{
    // Fields to be shown on create/edit forms
    protected function configureFormFields(FormMapper $formMapper)
    {
        $formMapper
            ->add('name', 'text', array('label' => 'Name'))
			->add('description', 'text', array('label' => 'Description'))
			->add('max_place', 'integer', array('label' => 'Max place'))
			->add('date_start_inscription', 'datetime', array('label' => 'Date start inscription'))
			->add('date_end_inscription', 'datetime', array('label' => 'Date end inscription'))
			->add('date_start', 'datetime', array('label' => 'Date start'))
			->add('date_end', 'datetime', array('label' => 'Date end'))
			->add('credit', 'integer', array('label' => 'Credit'))
			/*->add('activities', 'sonata_type_collection',
				array('by_reference' => false,
						'btn_add' => 'Add activity'),
                            array(
                            'edit' => 'inline',
                            'inline' => 'table',
                            'sortable' => 'id',
						))*/
        ;
    }

    // Fields to be shown on filter forms
    protected function configureDatagridFilters(DatagridMapper $datagridMapper)
    {
        $datagridMapper
            ->add('name')
            ->add('description')
            ->add('maxPlace')
            ->add('dateStartInscription')
            ->add('dateEndInscription')
            ->add('dateStart')
            ->add('dateEnd')
            ->add('credit')
			;
    }

    // Fields to be shown on lists
    protected function configureListFields(ListMapper $listMapper)
    {
        $listMapper
            ->addIdentifier('name')
            ->add('description')
            ->add('maxPlace')
            ->add('dateStartInscription')
            ->add('dateEndInscription')
            ->add('dateStart')
            ->add('dateEnd')
            ->add('credit')
        ;
    }

    public function prePersist($module)
    {
        $this->preUpdate($module);
    }

    public function preUpdate($module)
    {
 		foreach ($module->getActivities() as $a) {
            $a->setModule($module);
        }
    }
}
