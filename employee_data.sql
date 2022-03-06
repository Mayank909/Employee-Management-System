-- phpMyAdmin SQL Dump
-- version 4.8.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Mar 06, 2022 at 06:29 PM
-- Server version: 10.1.37-MariaDB
-- PHP Version: 7.3.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `employee_data`
--

-- --------------------------------------------------------

--
-- Table structure for table `department`
--

CREATE TABLE `department` (
  `Dep_name` varchar(15) NOT NULL,
  `Dep_id` varchar(5) NOT NULL,
  `mgr_id` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `department`
--

INSERT INTO `department` (`Dep_name`, `Dep_id`, `mgr_id`) VALUES
('Market', 'd01', 'e10'),
('Sales', 'd02', 'e01'),
('Research', 'd03', 'e05');

-- --------------------------------------------------------

--
-- Table structure for table `emp`
--

CREATE TABLE `emp` (
  `Name` varchar(20) DEFAULT NULL,
  `L_name` varchar(15) NOT NULL,
  `eid` varchar(5) NOT NULL,
  `Address` varchar(20) NOT NULL,
  `City` varchar(15) NOT NULL,
  `salary` int(7) NOT NULL,
  `Dep_no` varchar(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `emp`
--

INSERT INTO `emp` (`Name`, `L_name`, `eid`, `Address`, `City`, `salary`, `Dep_no`) VALUES
('Anup', 'sigh', 'e01', '', '', 10000, 'd03'),
('Ram', 'singh', 'e04', 'moglines', 'Indore', 20000, 'd02'),
('Jay', 'Jain', 'e05', 'rajwada', 'Indore', 10000, 'd03'),
('karan', 'kapur', 'e07', '', '', 10000, 'd02'),
('Manish', 'Yadav', 'e10', 'Mahunaka', 'Indore', 10000, 'd02');

-- --------------------------------------------------------

--
-- Table structure for table `login`
--

CREATE TABLE `login` (
  `username` varchar(20) NOT NULL,
  `password` varchar(10) NOT NULL DEFAULT 'admin',
  `eid` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `login`
--

INSERT INTO `login` (`username`, `password`, `eid`) VALUES
('admin', 'admin', 'e01'),
('Anup', 'Anup', 'e01'),
('Jay', 'Jay', 'e05'),
('Karan', 'Karan', 'e07'),
('Manish', 'Manish', 'e10'),
('Ram', 'ram', 'e04');

-- --------------------------------------------------------

--
-- Table structure for table `project`
--

CREATE TABLE `project` (
  `dop_no` varchar(5) NOT NULL,
  `Pname` varchar(15) NOT NULL,
  `pid` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `project`
--

INSERT INTO `project` (`dop_no`, `Pname`, `pid`) VALUES
('d01', 'RST', 'p01'),
('d03', 'Projectf', 'p02'),
('d02', 'MRT', 'p03');

-- --------------------------------------------------------

--
-- Table structure for table `works`
--

CREATE TABLE `works` (
  `pid` varchar(5) NOT NULL,
  `eid` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `works`
--

INSERT INTO `works` (`pid`, `eid`) VALUES
('p02', 'e01'),
('p01', 'e04'),
('p02', 'e05');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `department`
--
ALTER TABLE `department`
  ADD PRIMARY KEY (`Dep_id`),
  ADD KEY `mgr_id` (`mgr_id`);

--
-- Indexes for table `emp`
--
ALTER TABLE `emp`
  ADD PRIMARY KEY (`eid`),
  ADD KEY `Dep_no` (`Dep_no`);

--
-- Indexes for table `login`
--
ALTER TABLE `login`
  ADD UNIQUE KEY `password` (`password`),
  ADD UNIQUE KEY `username` (`username`),
  ADD KEY `eid` (`eid`);

--
-- Indexes for table `project`
--
ALTER TABLE `project`
  ADD PRIMARY KEY (`pid`),
  ADD KEY `dop_no` (`dop_no`);

--
-- Indexes for table `works`
--
ALTER TABLE `works`
  ADD PRIMARY KEY (`eid`,`pid`),
  ADD KEY `pid` (`pid`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `department`
--
ALTER TABLE `department`
  ADD CONSTRAINT `department_ibfk_1` FOREIGN KEY (`mgr_id`) REFERENCES `emp` (`eid`);

--
-- Constraints for table `emp`
--
ALTER TABLE `emp`
  ADD CONSTRAINT `emp_ibfk_1` FOREIGN KEY (`Dep_no`) REFERENCES `department` (`Dep_id`);

--
-- Constraints for table `login`
--
ALTER TABLE `login`
  ADD CONSTRAINT `login_ibfk_1` FOREIGN KEY (`eid`) REFERENCES `emp` (`eid`);

--
-- Constraints for table `project`
--
ALTER TABLE `project`
  ADD CONSTRAINT `project_ibfk_1` FOREIGN KEY (`dop_no`) REFERENCES `department` (`Dep_id`);

--
-- Constraints for table `works`
--
ALTER TABLE `works`
  ADD CONSTRAINT `works_ibfk_1` FOREIGN KEY (`eid`) REFERENCES `emp` (`eid`),
  ADD CONSTRAINT `works_ibfk_2` FOREIGN KEY (`pid`) REFERENCES `project` (`pid`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
