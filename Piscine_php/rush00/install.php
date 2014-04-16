#!/usr/bin/php
<?php

include_once('connect.php');

if ($argc < 3)
{
	echo "./install.php login password\n";
	exit();
}

$user = $argv[1];
$pwd = $argv[2];

file_put_contents(".credentials", "$user\n$pwd");
$link = mysqli_connect('127.0.0.1', $user, $pwd);

if (!$link)
	die('Erreur de connexion ('.mysqli_connect_errno().') '.mysqli_connect_error());

if (mysqli_query($link, "CREATE DATABASE IF NOT EXISTS `minishop` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;"));
	echo "Creating database...\n";
if (mysqli_query($link, "USE `minishop`;"));
	echo "Selecting minishop...\n";

if (mysqli_query($link, "DROP TABLE IF EXISTS `articles`;"));
	echo "Dropping table articles...\n";
if (mysqli_query($link, "CREATE TABLE IF NOT EXISTS `articles` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  `category_id` int(10) unsigned NOT NULL,
  `description` text NOT NULL,
  `image_url` varchar(255) NOT NULL,
  `price` float NOT NULL,
  PRIMARY KEY (`id`),
  KEY `name` (`name`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=3 ;"));
	echo "Creating table articles...\n";

if (mysqli_query($link, "INSERT INTO `articles` (`id`, `name`, `category_id`, `description`, `image_url`, `price`) VALUES
	(1, 'Belle guitare classique', 7, 'Elle vous ravira.', 'http://www.bressey-sur-tille.fr/wp-content/uploads/2012/10/guitare.jpg', 350),
	(2, 'Piano de merde', 3, 'Il a l''air bien mais ne le prenez pas.', 'http://cms.rolandus.com/assets/images/products/gallery/v-piano_grand_angle_open_half_gal.jpg', 8500),
	(3, 'Trompette', 6, 'Ceci est une trompette.', 'http://www.hbmusic.fr/images/Trompette_BS_ChallengerMBX.jpg', 352),
	(4, 'Saxophone', 6, 'Maecenas tempor adipiscing elementum. Proin a dolor malesuada, accumsan quam sed, hendrerit sapien. Phasellus adipiscing arcu nisi, eget porta nisi placerat ac. Quisque quis massa eget nisi pharetra commodo a faucibus nulla. Vestibulum tristique felis vitae elit interdum, nec ultricies nunc fringilla. In hac habitasse platea dictumst. Duis ut velit et massa volutpat egestas. Nulla laoreet, nibh vitae tempor hendrerit.', 'http://www.hbmusic.fr/images/vent_sax_yas275.gif', 854),
	(5, 'Clarinette', 6, 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur convallis pellentesque nunc vitae tincidunt. Nullam rhoncus nulla eu justo sagittis, sed dictum magna tincidunt. Vestibulum scelerisque laoreet eros, at fringilla nibh viverra vitae. In aliquet lacinia nisi.', 'http://www.arpeges.fr/upload/produit/A07913.jpg', 362),
	(6, 'Flûte traversière', 6, 'Mauris vulputate lacus ut sapien venenatis, non venenatis magna varius. Donec sagittis dui nisi, eu bibendum magna consectetur a.', 'http://www.hbmusic.fr/images/711_flute_sankyo_cf201.jpg', 2890),
	(7, 'Trombone', 6, 'Cras porttitor eros metus, at pulvinar turpis pretium sit amet. Etiam non euismod leo, et porttitor risus. Cras id nunc eget ante tincidunt vestibulum eu a est. Fusce sed ipsum convallis, accumsan ligula ac, suscipit velit. Phasellus sagittis diam erat, ac adipiscing odio interdum ut. Phasellus quis gravida enim, eu adipiscing mauris. Cras ut posuere magna. Praesent pulvinar est ut scelerisque tempus.', 'http://www.woodwindandbrass.co.uk/acatalog/bauhaus500_slidetrumpet.jpg', 190),
	(8, 'Tuba', 6, 'Proin ultrices, magna id suscipit suscipit, nibh ante lobortis ante, nec rutrum turpis eros aliquam ipsum. Proin sed justo id erat porttitor lacinia. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce sed ultrices augue, lacinia dignissim sem. Pellentesque dignissim dictum arcu at dapibus. Nulla leo ante, pharetra nec elit sit amet, euismod ullamcorper mauris. Sed congue nulla eget justo luctus pharetra. Maecenas faucibus velit sit amet aliquet commodo. Pellentesque lacinia mollis aliquam. Nullam lacinia leo in dapibus posuere. Morbi nec faucibus metus, eu vulputate ante. Mauris laoreet tortor mauris, a condimentum neque porttitor vel.', 'http://ic10.ecvv.com/upload/Product/20092/400x400/China_Tuba2009220948597.jpg', 1500),
	(9, 'Flûte à bec', 6, 'Fusce sed ultrices augue, lacinia dignissim sem. Pellentesque dignissim dictum arcu at dapibus. Nulla leo ante, pharetra nec elit sit amet, euismod ullamcorper mauris. Sed congue nulla eget justo luctus pharetra. Maecenas faucibus velit sit amet aliquet commodo. Pellentesque lacinia mollis aliquam.', 'http://www.brindilles.fr/upload/image/-image-29104-grande.jpg', 9),
	(10, 'Accordéon', 6, 'Curabitur convallis pellentesque nunc vitae tincidunt. Nullam rhoncus nulla eu justo sagittis, sed dictum magna tincidunt. Vestibulum scelerisque laoreet eros, at fringilla nibh viverra vitae. In aliquet lacinia nisi.', 'http://fr.playhohner.com/typo3temp/pics/169b7b87cf.png', 1800),
	(11, 'Harmonica', 6, 'Quisque quis massa eget nisi pharetra commodo a faucibus nulla. Vestibulum tristique felis vitae elit interdum, nec ultricies nunc fringilla. In hac habitasse platea dictumst. Duis ut velit et massa volutpat egestas. Nulla laoreet, nibh vitae tempor hendrerit, augue risus commodo nisl, in egestas justo massa sit amet purus.', 'http://majorpigalle.com/img/illustrations/chromatic-amadeus-ad.png', 89),
	(12, 'Banjo', 7, 'Sed tincidunt risus vitae varius mollis. Cras tempor congue eros vel auctor. Phasellus vitae sem ac risus convallis fermentum. In congue lorem a nunc rutrum dignissim. Cras mattis justo quis risus varius, et porttitor nunc posuere. Donec ullamcorper felis sit amet diam ultricies elementum. Fusce sollicitudin iaculis dictum. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.', 'http://www.millennium-music.com/acatalog/PROD-GR3926-L.jpg', 189),
	(13, 'Derbouka', 7, 'Donec semper risus vel arcu faucibus bibendum at at velit. Phasellus vitae gravida lectus. Suspendisse dictum ipsum neque, non convallis tortor convallis sed. Vivamus nec justo euismod, lobortis nisi sit amet, luctus sapien. Etiam nibh tortor, molestie ac pulvinar ullamcorper, molestie ut diam. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Integer id porttitor eros, id blandit odio. Proin blandit, ante nec tincidunt elementum, odio felis adipiscing massa, et volutpat ante magna id purus', 'http://larbitemsamani.free.fr/images/derbouga3.jpg', 159),
	(14, 'Mandole', 7, 'Cras mattis justo quis risus varius, et porttitor nunc posuere. Donec ullamcorper felis sit amet diam ultricies elementum. Fusce sollicitudin iaculis dictum. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Donec semper risus vel arcu faucibus bibendum at at velit. Phasellus vitae gravida lectus. Suspendisse dictum ipsum neque, non convallis tortor convallis sed.', 'http://www.hellopro.fr/images/produit-2/7/0/3/mandoline-sunburst-2781307.jpg', 79),
	(15, 'Zurna', 7, 'Donec sagittis dui nisi, eu bibendum magna consectetur a. Vestibulum congue urna est, a porttitor purus porttitor non.', 'http://danshanesanatmerkezi.com/wp-content/uploads/2013/10/iuuq_NV_00xxx_SL_nejzbsj_SL_dpn0vqmpbe09b_2NU__2NU_g5f8_2NU_7iol_SL_kqh.jpg', 159),
	(16, 'Table de mixage', 4, 'Donec semper risus vel arcu faucibus bibendum at at velit. Phasellus vitae gravida lectus. Suspendisse dictum ipsum neque, non convallis tortor convallis sed. Vivamus nec justo euismod, lobortis nisi sit amet, luctus sapien. Etiam nibh tortor, molestie ac pulvinar ullamcorper, molestie ut diam. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae.', 'http://boulanger.scene7.com/is/image/Boulanger/bfr_overlay?layer=comp&\$t1=&\$product_id=Boulanger/3362934740320_h_f_l_0&wid=400&hei=400', 259),
	(17, 'MPC 4000', 4, 'Fusce sed ipsum convallis, accumsan ligula ac, suscipit velit. Phasellus sagittis diam erat, ac adipiscing odio interdum ut. Phasellus quis gravida enim, eu adipiscing mauris. Cras ut posuere magna. Praesent pulvinar est ut scelerisque tempus.', 'http://static.djbooth.net/pics-equip/mpc500.jpg', 699),
	(18, 'Cable', 4, 'Donec sagittis dui nisi, eu bibendum magna consectetur a. Vestibulum congue urna est, a porttitor purus porttitor non.', 'http://www.cinemotion.biz/archivos/productos/mpc-audio-power-mk3-shop.jpg', 9),
	(19, 'Elvis', 5, 'Maecenas tempor adipiscing elementum. Proin a dolor malesuada, accumsan quam sed, hendrerit sapien. Phasellus adipiscing arcu nisi, eget porta nisi placerat ac. Quisque quis massa eget nisi pharetra commodo a faucibus nulla. Vestibulum tristique felis vitae elit interdum, nec ultricies nunc fringilla. In hac habitasse platea dictumst. Duis ut velit et massa volutpat egestas. Nulla laoreet, nibh vitae tempor hendrerit, augue risus commodo nisl, in egestas justo massa sit amet purus.', 'http://medias.audiofanzine.com/images/thumbs3/shure-55sh-series-ii-94798.jpg', 899),
	(20, 'Pied de micro', 5, 'Curae; Integer id porttitor eros, id blandit odio. Proin blandit, ante nec tincidunt elementum, odio felis adipiscing massa, et volutpat ante magna id purus.', 'http://www.hellopro.fr/images/produit-2/0/2/9/pied-de-microphone-mccrypt-tlk-m11-2804920.jpg', 59),
	(21, 'Casque', 4, 'Mauris vulputate lacus ut sapien venenatis, non venenatis magna varius. Donec sagittis dui nisi, eu bibendum magna consectetur a. Vestibulum congue urna est, a porttitor purus porttitor non. Quisque ac tellus lobortis, aliquet arcu sed, convallis nisl. Cras porttitor eros metus, at pulvinar turpis pretium sit amet. Etiam non euismod leo, et porttitor risus. Cras id nunc eget ante tincidunt vestibulum eu a est.', 'http://4.bp.blogspot.com/_ZKEQoUFwe3g/Spk4pjSqR7I/AAAAAAAACK4/2WL5tG4Ryro/s400/srh840+1.jpg', 559),
	(22, 'Micro batterie', 5, 'Mauris vulputate lacus ut sapien venenatis, non venenatis magna varius. Donec sagittis dui nisi, eu bibendum magna consectetur a. Vestibulum congue urna est, a porttitor purus porttitor non. Quisque ac tellus lobortis, aliquet arcu sed, convallis nisl. Cras porttitor eros metus, at pulvinar turpis pretium sit amet. Etiam non euismod leo, et porttitor risus. Cras id nunc eget ante tincidunt vestibulum eu a est. Fusce sed ipsum convallis, accumsan ligula ac, suscipit velit. Phasellus sagittis diam erat, ac adipiscing odio interdum ut. Phasellus quis gravida enim, eu adipiscing mauris. Cras ut posuere magna. Praesent pulvinar est ut scelerisque tempus.\r\n', 'http://www.reflex-rockshop.co.uk/ekmps/shops/reflex/images/pg52-shure-microphone-professional-dynamic-kick-drum-microphone-sure-pg-series-2249-p.jpg', 89),
	(23, 'Médiator Dunlop', 9, 'Praesent turpis turpis, dictum ac venenatis ac, vehicula bibendum ante. Pellentesque vitae massa sed est rhoncus fermentum. Aliquam elementum et sapien vitae vestibulum. Nam elementum consectetur magna, a adipiscing tortor lobortis vel. Etiam accumsan a ipsum in fermentum. Etiam aliquam quam nec magna porttitor laoreet. Ut sollicitudin vestibulum arcu, nec consequat nisi viverra scelerisque. Curabitur porttitor eros quis hendrerit aliquam.', 'http://www.hbmusic.fr/images/div_mediator_dunlop088m_nylon.jpg', 4),
	(24, 'Capodastre Dunlop', 9, 'Vivamus venenatis est nunc, vitae dapibus elit pellentesque eget. Vivamus mattis augue sit amet neque tincidunt, in semper tortor aliquet. Ut ac urna quis ipsum laoreet congue nec vel leo. Vivamus ornare id dolor a sodales. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Fusce mauris metus, congue aliquam ultricies eu, cursus at eros. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Sed elementum commodo nibh eu malesuada. Nullam dolor elit, tristique at dolor id, gravida eleifend nisi. Integer et mauris sollicitudin, bibendum justo ut, dignissim ipsum. Phasellus eu tortor turpis. Suspendisse suscipit venenatis accumsan. Cras lobortis dui nisl, in rutrum massa convallis nec. Integer consectetur eget arcu sit amet bibendum. Suspendisse lacinia a libero ut bibendum.', 'http://www.hbmusic.fr/images/Capo%20dunlopTRIGGER.jpg', 12),
	(25, 'Anche pour saxophone', 9, 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus hendrerit lacus rutrum nisi adipiscing tristique. Vivamus suscipit dui quis velit sodales, molestie varius purus varius. Phasellus eu lorem mi. Pellentesque tincidunt vitae velit ut placerat. Vivamus facilisis nibh eleifend dolor congue dapibus. Phasellus dictum magna leo, aliquet mollis tellus porta non. Pellentesque nec posuere tellus.', 'http://www.feelingmusique.com/fr/images_db/vent_acc_fibracell_clar1.jpg', 22),
	(26, 'Batterie infernale', 2, 'Quisque ultricies nec est sit amet tempus. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Ut eu purus at risus dapibus dignissim sit amet sit amet erat. Nullam egestas lorem elit, ac vulputate nisi tristique a. Sed nec lectus nec massa porta consequat sit amet eget nisi. Nullam ut mauris malesuada, pharetra dui sit amet, ultricies nisl. Nullam eleifend erat sit amet rhoncus suscipit. Praesent eget dictum nunc. Donec laoreet feugiat viverra.', 'http://auto.img.v4.skyrock.net/3898/21493898/pics/1302454784.jpg', 1600),
	(27, 'Batterie ridicule', 2, 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam consectetur ante ut sem facilisis aliquet. Proin semper tincidunt luctus. Mauris pretium molestie dictum. Cras lacus nisi, ullamcorper non sapien eget, fringilla viverra nulla. Duis id erat leo. Donec id cursus velit. Nulla ac tincidunt tellus, id auctor lectus. Maecenas suscipit viverra rutrum. Etiam eu mollis eros. Pellentesque porta, est at eleifend tincidunt, enim nunc elementum tortor, eu vehicula turpis tortor in eros. Vivamus vitae varius sem. Pellentesque in interdum risus, non scelerisque libero.\r\n\r\nPraesent turpis turpis, dictum ac venenatis ac, vehicula bibendum ante. Pellentesque vitae massa sed est rhoncus fermentum. Aliquam elementum et sapien vitae vestibulum. Nam elementum consectetur magna, a adipiscing tortor lobortis vel. Etiam accumsan a ipsum in fermentum. Etiam aliquam quam nec magna porttitor laoreet. Ut sollicitudin vestibulum arcu, nec consequat nisi viverra scelerisque. Curabitur porttitor eros quis hendrerit aliquam.', 'http://www.blogcdn.com/www.engadget.com/media/2008/02/2-21-08-rock-band-drums.jpg', 72),
	(28, 'Batterie électrique', 2, 'Phasellus convallis justo eu accumsan adipiscing. Etiam sed elit nibh. Praesent in erat ornare dui semper condimentum nec at sem. Nunc fringilla quis enim eget imperdiet. Donec eu gravida lacus. Fusce luctus mi pretium, imperdiet enim et, pulvinar lectus. Etiam laoreet mauris eu nisi semper sollicitudin. Nunc elementum semper eros, eget tincidunt nibh placerat in. Etiam pharetra augue vitae neque viverra pulvinar. Aliquam imperdiet posuere nisl et ornare. Vivamus semper bibendum urna sed vulputate. Maecenas elit est, feugiat sit amet lacinia vitae, elementum vitae velit. Maecenas at lectus nunc. Curabitur eget magna magna. Proin facilisis aliquam sodales. Donec accumsan posuere dui in blandit.', 'http://www.rolandce.com/mediafiles/images/products/middle/TD-15K_F_300_FNL-02.jpg', 842),
	(29, 'Tam tam', 2, 'Donec suscipit vulputate dui in sollicitudin. Sed pharetra elit ligula, in accumsan felis tempor mollis. Morbi tincidunt turpis vel lacus mattis pellentesque. Quisque nisi eros, lacinia ac eros quis, mollis molestie odio. Curabitur at diam et lectus vehicula euismod. Ut aliquet fringilla quam, sed cursus elit convallis non. Sed sodales, orci quis tristique congue, risus est ornare nisl, non ultrices leo ligula eu lorem.', 'http://www.soundtravels.co.uk/upload/all/mi/MID027.jpg', 160),
	(30, 'Maracas andalouses', 2, 'Pellentesque tincidunt laoreet neque id viverra. Nam condimentum commodo mauris, sed facilisis diam. Phasellus eget nibh nibh. Suspendisse convallis ultricies metus quis dictum. Sed non ligula orci. Phasellus tincidunt leo ut orci fermentum tristique. Nunc eget nunc nec lectus dapibus iaculis. Suspendisse potenti. Ut porttitor placerat lectus, ut pretium massa consectetur in. Proin imperdiet mi sit amet dapibus consequat. Fusce lacinia sed est ac imperdiet. Nulla pretium velit urna, vitae ultrices dui placerat consequat.\r\n', 'https://organologia-grupo2.wikispaces.com/file/view/maracas.jpg/111004553/373x377/maracas.jpg', 45),
	(31, 'Triangle', 2, 'Donec nec lacus ut tellus auctor sollicitudin sed quis felis. Quisque non feugiat purus, at posuere lacus. Donec varius sapien non nunc scelerisque, eget semper nibh tempor. In hac habitasse platea dictumst. Donec fermentum lacinia sapien eget volutpat. Ut eu tristique est, nec porta nisi. In id quam odio. Integer libero orci, sollicitudin vel pharetra vel, lacinia id lacus.', 'http://www.peanutgallery.com.au/catalogue/musical_instruments/goki_childrens_triangle/image/?size=3000x3000&helper=1306733094.39', 24),
	(32, 'Tambour enfant', 2, 'Fusce feugiat tellus non eros lacinia, et feugiat odio tempor. Aenean ullamcorper ligula libero, vel pellentesque nisi accumsan eget. Mauris aliquet lobortis ligula, vel blandit neque rutrum nec. Quisque dui odio, laoreet in dui quis, iaculis cursus arcu. Donec dolor lectus, mollis id tincidunt id, tempus et risus. Quisque arcu nunc, tristique eu gravida eget, lacinia vel ante. Aliquam ut tortor sollicitudin, accumsan lacus id, commodo augue. Donec elementum egestas lectus at sodales. Ut placerat orci arcu. Pellentesque sodales condimentum purus laoreet suscipit. Fusce consectetur est id odio aliquet, non dapibus libero malesuada. Nulla id tellus condimentum, sollicitudin sapien et, rutrum tellus.', 'http://www.jeuxenbois.com/77-176-large/tambour-baguettes-bois.jpg', 55),
	(33, 'Cable jack mâle - mâle', 8, 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam vulputate non ante sed consectetur. Proin quis leo et sem venenatis posuere. Sed vehicula volutpat justo, non pulvinar velit imperdiet eget. Suspendisse tempor a nisl ut tincidunt. Aliquam vitae pulvinar est. Etiam tincidunt elit eu ipsum eleifend, sed tempus purus facilisis. Praesent at ornare libero, non commodo mi. Nam consequat nisl sed ante fringilla pulvinar. Phasellus eu sodales eros, sed tincidunt orci. Nullam ut varius massa.', 'http://www.audiophonics.fr/images/7090_CABLE_MINIJACK_MINIJACK.gif', 8),
	(34, 'Cable ultra résistant', 8, 'Cras posuere fringilla lacus, quis blandit mi condimentum egestas. Vivamus cursus ante est, a luctus ipsum rutrum non. Morbi ut feugiat tellus. Aenean hendrerit, nunc et ornare sollicitudin, justo justo volutpat ante, ac porta ante lacus sit amet nisl. Morbi aliquet ligula a vestibulum ultrices. Duis justo arcu, eleifend ut velit et, mollis ultrices augue. Morbi lobortis quam eget vehicula dictum. Donec pulvinar rhoncus diam eu gravida. Aliquam varius nisi vitae elit lacinia, volutpat dictum dui ornare. Phasellus fringilla, erat at faucibus tempor, neque est interdum tellus, non hendrerit mauris est quis ipsum. Sed eget enim dui. Mauris et nisl quis quam malesuada volutpat. Maecenas laoreet enim sed molestie rutrum. Etiam quis varius augue. Phasellus dapibus erat a faucibus auctor. Nullam nunc augue, rhoncus ac nunc sed, consequat dignissim massa.', 'http://www.piano-lille.fr/364-750-large/cable-jack-jack-6-metres-sgc6-dl.jpg', 24),
	(35, 'Adaptateur mini-jack / jack', 8, 'Pellentesque tincidunt laoreet neque id viverra. Nam condimentum commodo mauris, sed facilisis diam. Phasellus eget nibh nibh. Suspendisse convallis ultricies metus quis dictum. Sed non ligula orci. Phasellus tincidunt leo ut orci fermentum tristique. Nunc eget nunc nec lectus dapibus iaculis. Suspendisse potenti. Ut porttitor placerat lectus, ut pretium massa consectetur in. Proin imperdiet mi sit amet dapibus consequat. Fusce lacinia sed est ac imperdiet. Nulla pretium velit urna, vitae ultrices dui placerat consequat.', 'http://i2.cdscdn.com/pdt2/6/4/8/1/700x700/gen6922255432648/rw/adaptateur-3-5-male-vers-2-5mm-femelle-audio-jack.jpg', 12),
	(36, 'Ecouteurs intra haute qualité', 8, 'Donec nec lacus ut tellus auctor sollicitudin sed quis felis. Quisque non feugiat purus, at posuere lacus. Donec varius sapien non nunc scelerisque, eget semper nibh tempor. In hac habitasse platea dictumst. Donec fermentum lacinia sapien eget volutpat. Ut eu tristique est, nec porta nisi. In id quam odio. Integer libero orci, sollicitudin vel pharetra vel, lacinia id lacus.', 'http://i2.cdscdn.com/pdt2/2/4/2/1/700x700/jbl0500363162242/rw/ecouteurs-intra-auculaires-jbl.jpg', 44),
	(37, 'Orgue', 3, 'Prix à débattre avec la paroisse.\r\nFusce feugiat tellus non eros lacinia, et feugiat odio tempor. Aenean ullamcorper ligula libero, vel pellentesque nisi accumsan eget. Mauris aliquet lobortis ligula, vel blandit neque rutrum nec. Quisque dui odio, laoreet in dui quis, iaculis cursus arcu. Donec dolor lectus, mollis id tincidunt id, tempus et risus. Quisque arcu nunc, tristique eu gravida eget, lacinia vel ante. Aliquam ut tortor sollicitudin, accumsan lacus id, commodo augue. Donec elementum egestas lectus at sodales. Ut placerat orci arcu. Pellentesque sodales condimentum purus laoreet suscipit. Fusce consectetur est id odio aliquet, non dapibus libero malesuada. Nulla id tellus condimentum, sollicitudin sapien et, rutrum tellus.', 'http://synth-kopp.wifeo.com/images/angoul_orgue-ea453.jpg', 540),
	(38, 'Piano à queue bleu', 3, 'Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean rutrum lacus quis lacus ultrices elementum. Aenean sagittis iaculis nulla sit amet elementum. Cras ac tellus mi. Quisque venenatis tempor sodales. Sed erat elit, sollicitudin ac fermentum sed, cursus eget risus. Nullam bibendum lobortis metus, ac facilisis velit adipiscing sed. Vestibulum commodo magna risus, et egestas nulla pulvinar eget. Mauris rutrum eget mi ultricies porta. Nunc porttitor nisi at nulla euismod venenatis. Phasellus ac velit odio. Sed vel elementum sem. Phasellus in libero tellus. In euismod tellus non orci placerat, quis malesuada diam gravida. Donec laoreet, est nec blandit semper, nisi mauris elementum arcu, at dignissim risus risus non metus. Sed convallis leo at magna faucibus auctor.', 'http://i2.cdscdn.com/pdt2/9/4/7/1/700x700/vil3048700082947/rw/piano-a-queue.jpg', 4000),
	(39, 'Piano électrique', 3, 'Nunc pharetra commodo dolor, sed malesuada neque tempus in. Maecenas sit amet mauris ac nibh tempus dictum. Vivamus lacinia nibh vitae mi faucibus sagittis. Phasellus magna nibh, ultrices sed fringilla eu, accumsan eu erat. Nunc nibh urna, euismod eu cursus euismod, ultrices et mi. Praesent lacinia euismod nunc a tempus. Vestibulum interdum ullamcorper metus, eu molestie nulla porta sed.', 'http://www.sunmusic.fr/1462-large_default/korg-sp-280-bk.jpg', 4500),
	(40, 'Orgue pour enfants', 3, 'Aliquam enim sapien, consectetur et euismod nec, malesuada vel ipsum. Aenean convallis sed ante quis placerat. Maecenas mollis, elit vel euismod commodo, leo tellus pellentesque felis, et elementum risus justo quis enim. Proin consectetur, mi id adipiscing sollicitudin, urna est laoreet augue, eu eleifend elit nulla at nunc. Donec hendrerit ipsum in euismod suscipit. Nunc sit amet neque urna. Morbi pellentesque et risus id auctor.', 'http://i2.cdscdn.com/pdt2/6/3/8/1/700x700/bon0047663430638/rw/orgue-electronique-parlant-ave.jpg', 120);"))
	echo "Inserting articles...\n";

if (mysqli_query($link, "DROP TABLE IF EXISTS `categories`;"));
	echo "Dropping table categories...\n";
if (mysqli_query($link, "CREATE TABLE IF NOT EXISTS `categories` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=10 ;"));
	echo "Creating table categories...\n";

if (mysqli_query($link, "INSERT INTO `categories` (`id`, `name`) VALUES
(2, 'Batterie et percussions'),
(3, 'Clavier'),
(4, 'Studio et Enregistrement'),
(5, 'Micros'),
(6, 'Instruments à vent'),
(7, 'Instruments traditionnels'),
(8, 'Câbles et connectique'),
(9, 'Accessoires');"));
	echo "Inserting categories...\n";

if (mysqli_query($link, "DROP TABLE IF EXISTS `orders`;"));
	echo "Dropping table orders...\n";
if (mysqli_query($link, "CREATE TABLE IF NOT EXISTS `orders` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `content` text NOT NULL,
  `date` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;"));
	echo "Creating table orders...\n";

if (mysqli_query($link, "DROP TABLE IF EXISTS `users`;"));
	echo "Dropping table users...\n";
if (mysqli_query($link, "CREATE TABLE IF NOT EXISTS `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `login` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `level` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `login` (`login`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=11 ;"));
	echo "Creating table users...\n";

if (mysqli_query($link, "INSERT INTO `users` (`id`, `login`, `password`, `level`) VALUES
(9, 'jbalestr', '8aca2602792aec6f11a67206531fb7d7f0dff59413145e6973c45001d0087b42d11bc645413aeff63a42391a39145a591a92200d560195e53b478584fdae231a', 10),
(10, 'mpillet', '8aca2602792aec6f11a67206531fb7d7f0dff59413145e6973c45001d0087b42d11bc645413aeff63a42391a39145a591a92200d560195e53b478584fdae231a', 10);"));
	echo "Inserting users...\n";
?>
