# Create function
function what_day{

  # Parse the results of date
  current_day=$(date | cut -d " " -f1)

  # Echo the result
  echo $current_day
}

# Call the function
what_day

}
