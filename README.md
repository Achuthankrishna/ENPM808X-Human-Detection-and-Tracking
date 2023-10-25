# Human Detection and Tracking

## Human Detection and Tracking Badges
![CICD Workflow status](https://github.com/Achuthankrishna/ENPM808X-Human-Detection-and-Tracking/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/Achuthankrishna/ENPM808X-Human-Detection-and-Tracking/branch/main/graph/badge.svg)](https://codecov.io/gh/Achuthankrishna/ENPM808X-Human-Detection-and-Tracking) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)


## Overview
The "Human Tracker for Robots" project is a cutting-edge proposal presented to Acme Robotics aimed at addressing the challenge of "Human Detection and Tracking" within an indoor office environment using a specially designed robotic module equipped with a monocular video camera. The primary goal of this project is to develop an advanced robotic system capable of identifying and tracking humans within an office setting. This project leverages computer vision and machine learning. This is an efficient solution for various applications, such as enhancing security, improving workplace safety, and automating certain tasks within an indoor environment. Main features of the module include Human detection and Real-time Tracking. The Performance of the module is measured based on the detection accuracy and tracking precision.

### Team
(Group 10)
1. Kiran Patil
2. Vyshnav Achutan
3. Suryavardhan Reddy Chappidi

### Phase_0 (Project Proposal)
| Document           |Link                                                                                         |
| ------------------------- | -------------------------------------------------------------------------------------------- |
| Project Proposal          | [link](https://github.com/Achuthankrishna/ENPM808X-Human-Detection-and-Tracking/blob/main/Phase0%20-%20Proposal/ENPM808X%20-%20Midterm%20Phase%200%20(Proposal).pdf) |
| Quad Chart                | [link](https://github.com/Achuthankrishna/ENPM808X-Human-Detection-and-Tracking/blob/main/Phase0%20-%20Proposal/QuadChart.png) |
| UML Diagram               | [link](https://github.com/Achuthankrishna/ENPM808X-Human-Detection-and-Tracking/blob/main/UML/UML.png) |
| Activity Diagram          | [link](https://github.com/Achuthankrishna/ENPM808X-Human-Detection-and-Tracking/blob/main/UML/ActivityDiagram.png) |
| Proposal Video            | [link](https://drive.google.com/file/d/10-ACmZfWdRRPJYiRuZzHNGz2BmWI6FlM/view?usp=sharing) |


### Phase_1
| Document           |Link                                                                                         |
| ------------------------- | -------------------------------------------------------------------------------------------- |
| UML Diagram               | [link](https://github.com/Achuthankrishna/ENPM808X-Human-Detection-and-Tracking/blob/Development_branch/UML/UML_revised.png) |
| Proposal Video            | [link](https://drive.google.com/drive/folders/12MTIUhz1Iw60CUklfgAJ4cyKDgVU5TD8?usp=share_link) |
| AIP                       | [link](https://docs.google.com/spreadsheets/d/1wyLYvweVdQvH0OAug5pCWzMBC9qM7BZ0RR3IT80mlfs/view?usp=sharing) |
| Sprint Planning & Review  | [link](https://docs.google.com/document/d/1HD9eCnWuII8pH6mdCwwa3JQ9on-ul-u7y1zGJ7Iy514/view?usp=sharing) |

## Compilation
```
$ git clone https://github.com/Achuthankrishna/ENPM808X-Human-Detection-and-Tracking.git
$ cd ENPM808X-Human-Detection-and-Tracking
$ cmake -S ./ -B build/
$ cmake --build build/
```
## Testing
```
$ cd build/
$ ctest --test-dir build/
```
## Notes
- The results for cpplint and cppcheck are included in the results folder.
- Doxygen-generated docs are present in the Docs folder.

