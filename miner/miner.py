#!/usr/bin/env python3
#
# Copyright (c) 2018 Andrey Valyaev <dron.valyaev@gmail.com>
#
# This software may be modified and distributed under the terms
# of the MIT license.  See the LICENSE file for details.

from datetime import datetime
import random
import time
import traceback
import requests
import subprocess


url = 'http://localhost:4096'

print("%s: Started" % datetime.now().isoformat(' '))

while True:
	try:
		strength = requests.get(url).json()['score']['strength']

		tasks = requests.get(url + '/tasks').json()['tasks']
		if tasks:
			score = random.choice([t for t in tasks if t['type'] == 'mining'])['score']
			suffix = subprocess.check_output(
				['./zond-miner', '--strength', str(strength), score],
				timeout=60
			).rstrip()
			mined_time = datetime.now()
			print("%s: Mined: %s" % (mined_time.isoformat(' '), suffix))
			requests.put(url + '/score', json={'suffix': suffix})
		else:
			time.sleep(60)
	except subprocess.TimeoutExpired:
		pass
	except Exception as exc:
		traceback.print_exc()
		time.sleep(60)
