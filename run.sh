./clip_pic
scp -P [port] roi.jpg username@xxx.xxx.xxx.xxx:/username/mask2former_r101_8x2_50e_coco/
ssh -p [port] username@xxx.xxx.xxx.xxx '/username/miniconda3/bin/python /username/mask2former_r101_8x2_50e_coco/inference.py'
