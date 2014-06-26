<?php

namespace philemon\ModuleBundle\Admin;

use Sonata\AdminBundle\Admin\Admin;
use Sonata\AdminBundle\Datagrid\ListMapper;
use Sonata\AdminBundle\Datagrid\DatagridMapper;
use Sonata\AdminBundle\Form\FormMapper;
use philemon\ModuleBundle\Entity;

class BaremeAdmin extends Admin
{
    // Fields to be shown on create/edit forms
    protected function configureFormFields(FormMapper $formMapper)
    {
        $formMapper
            ->add('name', 'text', array('label' => 'Name'))
			->add('description', 'textarea', array('label' => 'Description'))
			->add('checkbox', 'text', array('label' => 'Numbers separated by ";" (1;2;3;4;5)'))
			->add('activity', 'sonata_type_model_list', array(
                    'btn_add'       => 'Add activity',
                    'btn_list'      => 'Activity list',
                    'btn_delete'    => false,
                    'btn_catalogue' => 'ModuleBundle' //Custom translation domain for buttons
                ), array(
                    'placeholder' => 'No Activity selected'
				))
			->add('displayo', 'integer', array('label' => "Ordre d'affichage"))
			;
    }

    // Fields to be shown on filter forms
    protected function configureDatagridFilters(DatagridMapper $datagridMapper)
    {
        $datagridMapper
			->add('activity')
            ->add('name')
            ->add('description')
            ->add('checkbox')
            ->add('displayo')
			;
    }

    // Fields to be shown on lists
    protected function configureListFields(ListMapper $listMapper)
    {
        $listMapper
			->addIdentifier('activity')
            ->addIdentifier('name')
            ->add('description')
            ->add('checkbox')
            ->add('displayo')
			;
    }
}
