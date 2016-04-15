CREATE TABLE `ft_table` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `login` varchar(8) NOT NULL DEFAULT 'toto',
  `groupe` enum('staff','student','other') NOT NULL,
  `date_de_creation` date NOT NULL,
  PRIMARY KEY (`id`)
);
