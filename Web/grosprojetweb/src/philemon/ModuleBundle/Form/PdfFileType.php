<?php

namespace philemon\ModuleBundle\Form;

use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\FormBuilderInterface; 

class PdfFileType extends AbstractType
{
    public function buildForm(FormBuilderInterface $builder, array $options)
    {
        $builder
			->add('activity')
            ->add('file')
        ;
    }
    public function getName()
    {
        return 'philemon_modulebundle_pdffiletype';
    }
}
