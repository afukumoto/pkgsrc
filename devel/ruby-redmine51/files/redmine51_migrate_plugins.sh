#!/bin/sh

@SYSCONFBASE@/rc.d/redmine51_unicorn.sh status > /dev/null 2>&1

if [ $? -eq 0 ]; then
	echo 'Please, stop Redmine unicorn before running this script.'
	exit 1
fi

cd @PREFIX@/@RM_DIR@

@RUBY@ bin/rake redmine:plugins:migrate RAILS_ENV=production
