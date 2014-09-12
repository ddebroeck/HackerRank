BIKE_WIDTH = 1
CAR_WIDTH = 2
TRUCK_WIDTH = 3

def get_ints(count)
	input = gets.chomp.split(' ').map(&:to_i)
	
	if input.length != count
		print "Invalid number of input parameters (expected " + count.to_s + ").\n"
		input = nil
	end

	return input
end

def main
	input = get_ints(2)
	if input.nil?
		return 1
	end
	
	freeway_length = input[0]
	if freeway_length < 2 || freeway_length > 100000
		print "Invalid freeway length provided (2 <= valid <= 100000).\n"
		return 1
	end

	test_cases = input[1]
	if test_cases < 1 || test_cases > 1000
		print "Invalid number of test cases provided (1 <= valid <= 1000).\n"
		return 1
	end

	width_array = get_ints(freeway_length)

	if width_array.nil?
		return 1
	end

	classified_segments = {BIKE_WIDTH => Array.new,  CAR_WIDTH => Array.new, TRUCK_WIDTH => Array.new}

	for i in 0...freeway_length
		width = width_array[i]
		case width
			when BIKE_WIDTH, CAR_WIDTH, TRUCK_WIDTH
				classified_segments[width].push(i)
			else
				print "An invalid width was provided, unable to continue with analysis.\n"
				return 1
		end
	end

	results = Array.new
	for i in 0...test_cases
		test_case = get_ints(2)
		if test_case.nil?
			return 1
		end

		i = test_case[0]
		j = test_case[1]

		diff = ((j - i) + 1)
		if diff < 2 || diff > [freeway_length, 1000].min
			print "An invalid test case was provided, skipping case.\n"
		else
			segments_array = (i..j).to_a

			result = nil
			segments_array.each{ |i| 
				result = BIKE_WIDTH and break if classified_segments[BIKE_WIDTH].include?(i)
				if result.nil?
					result = CAR_WIDTH if classified_segments[CAR_WIDTH].include?(i)
				end
			}
			result = TRUCK_WIDTH if result.nil?
			
			results.push(result) 
		end
	end

	results.each { |result| print result.to_s + "\n" }

	return 0;
end

main()