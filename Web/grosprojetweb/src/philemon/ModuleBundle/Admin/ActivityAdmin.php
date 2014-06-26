<?php

namespace philemon\ModuleBundle\Admin;

use Sonata\AdminBundle\Admin\Admin;
use Sonata\AdminBundle\Datagrid\ListMapper;
use Sonata\AdminBundle\Datagrid\DatagridMapper;
use Sonata\AdminBundle\Form\FormMapper;
use philemon\ModuleBundle\Entity;

class ActivityAdmin extends Admin
{
    // Fields to be shown on create/edit forms
    protected function configureFormFields(FormMapper $formMapper)
    {
        $formMapper
            ->add('name', 'text', array('label' => 'Name'))
			->add('description', 'text', array('label' => 'Description'))
			->add('max_place', 'integer', array('label' => 'Max place'))
			->add('subject', 'text', array('label' => 'Pdf url'))
			->add('type', 'choice', array('choices' => array(1 => 'Project', 2 => 'TP', 3 => 'Exam')))
			->add('date_start_inscription', 'datetime', array('label' => 'Date start inscription'))
			->add('date_end_inscription', 'datetime', array('label' => 'Date end inscription'))
			->add('date_start', 'datetime', array('label' => 'Date start'))
			->add('date_end', 'datetime', array('label' => 'Date end'))
			->add('date_start_co', 'datetime', array('label' => 'Date start correction'))
			->add('date_end_co', 'datetime', array('label' => 'Date end correction'))
			->add('module', 'sonata_type_model_list', array(
                    'btn_add'       => 'Add module',
                    'btn_list'      => 'Module list',
                    'btn_delete'    => false,
                    'btn_catalogue' => 'ModuleBundle' //Custom translation domain for buttons
                ), array(
                    'placeholder' => 'No Module selected'
                ))
			->add('baremes', 'sonata_type_collection',
				array('by_reference' => false,
						'btn_add' => 'Add bareme'),
                            array(
                            'edit' => 'inline',
                            'inline' => 'table',
                            'sortable' => 'id',
						))
	;
    }

    // Fields to be shown on filter forms
    protected function configureDatagridFilters(DatagridMapper $datagridMapper)
    {
        $datagridMapper
            ->add('module')
            ->add('name')
            ->add('description')
            ->add('subject')
            ->add('type', 'doctrine_orm_string', array(), 'choice', array('choices' => array(1 => 'Project', 2 => 'TP', 3 => 'Exam')))
            ->add('maxPlace')
            ->add('dateStartInscription')
            ->add('dateEndInscription')
            ->add('dateStart')
			->add('dateEnd')
            ->add('dateStartC')
            ->add('dateEndC')
			;
    }

    // Fields to be shown on lists
    protected function configureListFields(ListMapper $listMapper)
    {
        $listMapper
            ->addIdentifier('module')
            ->addIdentifier('name')
            ->add('description')
            ->add('subject')
			->add('type', 'string', array('template' => 'philemonModuleBundle:CRUD:enum_list_field.html.twig'))
            ->add('maxPlace')
            ->add('dateStartInscription')
            ->add('dateEndInscription')
            ->add('dateStart')
			->add('dateEnd')
            ->add('dateStartC')
            ->add('dateEndC')
        ;
    }

    public function prePersist($activity)
    {
        $this->preUpdate($activity);
    }

    public function preUpdate($activity)
    {
 		foreach ($activity->getBaremes() as $a) {
            $a->setActivity($activity);
        }
	}
}
