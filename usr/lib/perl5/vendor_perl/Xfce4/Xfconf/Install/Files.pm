package Xfconf::Install::Files;

$self = {
          'deps' => [
                      'Glib'
                    ],
          'inc' => '-I/usr/include/dbus-1.0 -I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include -I/usr/include/dbus-1.0 -I/usr/lib/dbus-1.0/include  -I. -Ibuild -I/build/xfconf/src/xfconf-4.12.0/xfconf-perl/.. -I..',
          'libs' => '-L/build/xfconf/src/xfconf-4.12.0/xfconf-perl/../common/.libs -L/build/xfconf/src/xfconf-4.12.0/xfconf-perl/../xfconf/.libs -lxfconf-gvaluefuncs -lxfconf-0 -ldbus-glib-1 -lgobject-2.0 -lglib-2.0 -ldbus-1 ',
          'typemaps' => [
                          'xfconfperl.typemap'
                        ]
        };

@deps = @{ $self->{deps} };
@typemaps = @{ $self->{typemaps} };
$libs = $self->{libs};
$inc = $self->{inc};

	$CORE = undef;
	foreach (@INC) {
		if ( -f $_ . "/Xfconf/Install/Files.pm") {
			$CORE = $_ . "/Xfconf/Install/";
			last;
		}
	}

	sub deps { @{ $self->{deps} }; }

	sub Inline {
		my ($class, $lang) = @_;
		if ($lang ne 'C') {
			warn "Warning: Inline hints not available for $lang language
";
			return;
		}
		+{ map { (uc($_) => $self->{$_}) } qw(inc libs typemaps) };
	}

1;
