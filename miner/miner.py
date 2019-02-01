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

while True:
	try:
		tasks = requests.get(url + '/tasks')
		if reply.status_code != 200:
			raise RuntimeError("error")
		tasks = [t for t in tasks.json()['tasks'] if t['type'] == 'mining']
		if tasks:
			score = random.choice(tasks)['score']
			start_time = datetime.now()
			suffix = subprocess.check_output('./zond-miner', score, timeout=60)
			end_time = datetime.now()
			print("%s: Mined: %s take %.2f sec" % (
				end_time.isoformat(' '),
				suffix,
				(end_time - start_time).total_seconds()
			))
			requests.post(url + '/score', json={'suffix': suffix})
		else:
			time.sleep(60)
	except subprocess.TimeoutExpired:
		pass
	except Exception as exc:
		traceback.print_exc()
		time.sleep(60)