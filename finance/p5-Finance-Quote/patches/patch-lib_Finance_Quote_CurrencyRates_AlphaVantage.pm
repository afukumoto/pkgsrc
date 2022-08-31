$NetBSD$

Tentative patch to fix currency rate retrieval
based on github.com/finance-quote/finance-quote/pulls #230

--- lib/Finance/Quote/CurrencyRates/AlphaVantage.pm.orig	2022-07-03 22:15:42.000000000 +0000
+++ lib/Finance/Quote/CurrencyRates/AlphaVantage.pm
@@ -53,14 +53,14 @@ sub multipliers
 {
   my ($this, $ua, $from, $to) = @_;
 
-  my $url = 'https://www.alphavantage.co/query?function=CURRENCY_EXCHANGE_RATE';
+  my $url = 'https://www.alphavantage.co/query?function=FX_DAILY';
   my $try_cnt = 0;
   my $json_data;
   do {
     $try_cnt += 1;
     my $reply = $ua->get($url
-        . '&from_currency=' . ${from}
-        . '&to_currency=' . ${to}
+        . '&from_symbol=' . ${from}
+        . '&to_symbol=' . ${to}
         . '&apikey=' . $this->{API_KEY});
 
     return unless ($reply->code == 200);
@@ -77,7 +77,8 @@ sub multipliers
     sleep (20) if (($try_cnt < 5) && ($json_data->{'Note'}));
   } while (($try_cnt < 5) && ($json_data->{'Note'}));
 
-  my $rate = $json_data->{'Realtime Currency Exchange Rate'}->{'5. Exchange Rate'};
+  my $target = substr($json_data->{'Meta Data'}->{'5. Last Refreshed'}, 0, 10);
+  my $rate = $json_data->{'Time Series FX (Daily)'}->{$target}->{'4. close'};
 
   return unless $rate + 0;
 
